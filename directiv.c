/***********************************************************************
 *
 *		DIRECTIVE.C
 *		Directive Routines for 68000 Assembler
 *
 * Description: The functions in this file carry out the functions of
 *		assembler directives. All the functions share the same
 *		calling sequence:
 *
 *		    general_name(size, label, op, errorPtr)
 *		    int size;
 *		    char *label, *op;
 *		    int *errorPtr;
 *
 *		The size argument contains the size code that was
 *		specified with the instruction (using the definitions
 *		in ASM.H) or 0 if no size code was specified. The label
 *		argument is a pointer to a string (which may be empty)
 *		containing the label from the line containing the
 *		directive. The op argument is a pointer to the first
 *		non-blank character after the name of the directive,
 *		i.e., the operand(s) of the directive. The errorPtr
 *		argument is used to return a status via the standard
 *		mechanism.
 *
 *      Author: Paul McKee
 *		ECE492    North Carolina State University
 *
 *        Date:	12/13/86
 *
 ************************************************************************/

#include "pila.h"
#include "asm.h"
#include "prc.h"

extern long gulOutLoc;
extern char gfPass2, endFlag;

extern char *listPtr;   /* Pointer to buffer where listing line is assembled
               (Used to put =XXXXXXXX in the listing for EQU's and SET's */

#define kcsseMax	50

int gcsse = 0;
struct SourceStackEntry gasse[kcsseMax];
struct SourceStackEntry *gpsseCur;


#ifdef ORG_DIRECTIVE
/***********************************************************************
 *
 *	Function org implements the ORG directive.
 *
 ***********************************************************************/

int org(int size, char *label, char *op, int *errorPtr)
{
    long    newLoc;
    char backRef;

    if (size)
        NEWERROR(*errorPtr, INV_SIZE_CODE);
    if (!*op) {
        NEWERROR(*errorPtr, SYNTAX);
        return NORMAL;
    }
    op = eval(op, &newLoc, &backRef, errorPtr);
    if (*errorPtr < SEVERE && !backRef) {
        NEWERROR(*errorPtr, INV_FORWARD_REF);
    } else if (*errorPtr < ERROR_RANGE) {
        if (isspace(*op) || !*op) {
            /* Check for an odd value, adjust to one higher */
            if (newLoc & 1) {
                NEWERROR(*errorPtr, ODD_ADDRESS);
                newLoc++;
            }
            gulOutLoc = newLoc;
            /* Define the label attached to this directive, if any */
            if (*label)
                define(label, gulOutLoc, gfPass2, errorPtr);
            /* Show new location counter on listing */
            listLoc();
        } else
            NEWERROR(*errorPtr, SYNTAX);
    }

    return NORMAL;
}
#endif

// A "code", "data", or "res" block ends when the next block begins or
// when a "end" statement is reached.  Each of handlers for those
// directives call this function to make sure the block is properly
// closed.

void EndBlock()
{
    switch (gbt) {
    case kbtData:
        gulDataLoc = gulOutLoc;
        break;

    case kbtCode:
        gulCodeLoc = gulOutLoc;
        break;

    case kbtResource:

        // Write the entire resource out

        AddResource(gfcResType, (unsigned short)gidRes, gpbResource,
                    gulOutLoc, FALSE);
        break;
    }

    // Just in case no new block is specified, we set the default
    // to code.

    gbt = kbtCode;
    gulOutLoc = gulCodeLoc;
}


/***********************************************************************
 *
 *	Function end implements the END directive.
 *
 ***********************************************************************/

int funct_end(int size, char *label, char *op, int *errorPtr)
{
    if (size)
        NEWERROR(*errorPtr, INV_SIZE_CODE);
    endFlag = TRUE;

    EndBlock();

    return NORMAL;
}


/***********************************************************************
 *
 *	Function equ implements the EQU directive.
 *
 ***********************************************************************/

int equ(int size, char *label, char *op, int *errorPtr)
{
    long    value;
    char backRef;

    if (size)
        NEWERROR(*errorPtr, INV_SIZE_CODE);
    if (!*op) {
        NEWERROR(*errorPtr, SYNTAX);
        return NORMAL;
    }
    op = eval(op, &value, &backRef, errorPtr);
    if (*errorPtr < SEVERE && !backRef) {
        NEWERROR(*errorPtr, INV_FORWARD_REF);

    } else if (*errorPtr < ERROR_RANGE) {
        if (isspace(*op) || !*op) {
            if (!*label) {
                NEWERROR(*errorPtr, LABEL_REQUIRED);
            } else {
                define(label, value, gfPass2, errorPtr);
                if (gfPass2 && gfListOn && *errorPtr < MINOR) {
                    sprintf(listPtr, "=%08lX ", value);
                    listPtr += 10;
                }
            }
        } else {
            NEWERROR(*errorPtr, SYNTAX);
        }
    }

    return NORMAL;
}


/***********************************************************************
 *
 *	Function set implements the SET directive.
 *
 ***********************************************************************/

int set(int size, char *label, char *op, int *errorPtr)
{
    long    value;
    int error;
    char backRef;
    symbolDef *symbol;

    if (size)
        NEWERROR(*errorPtr, INV_SIZE_CODE);

    if (!*op) {
        NEWERROR(*errorPtr, SYNTAX);
        return NORMAL;
    }

    op = eval(op, &value, &backRef, errorPtr);
    if (*errorPtr < SEVERE && !backRef) {
        NEWERROR(*errorPtr, INV_FORWARD_REF);

    } else if (*errorPtr < ERROR_RANGE) {
        if (isspace(*op) || !*op) {
            if (!*label) {
                NEWERROR(*errorPtr, LABEL_REQUIRED);

            } else {
                error = OK;
                symbol = define(label, value, gfPass2, &error);
                if (error == MULTIPLE_DEFS) {
                    if (symbol->flags & kfSymRedefinable)
                        symbol->value = value;
                    else {
                        NEWERROR(*errorPtr, MULTIPLE_DEFS);
                        return NORMAL;
                    }
                }
                symbol->flags |= kfSymRedefinable;
                if (gfPass2 && gfListOn) {
                    sprintf(listPtr, "=%08lX ", value);
                    listPtr += 10;
                }
            }
        } else {
            NEWERROR(*errorPtr, SYNTAX);
        }
    }

    return NORMAL;
}


/***********************************************************************
 *
 *	Function dc implements the DC directive.
 *
 ***********************************************************************/

int dc(int size, char *label, char *op, int *errorPtr)
{
    long outVal;
    char backRef;
    char string[260], *p;

    // No such thing as 'dc.s'.

    if (size == SHORT) {
        NEWERROR(*errorPtr, INV_SIZE_CODE);
        size = WORD;

        // If not specified, default size is WORD.

    } else if (!size) {
        size = WORD;
    }

    // Move location counter to a word boundary and fix the listing if doing
    // DC.W or DC.L (but not if doing DC.B, so DC.B's can be contiguous)

    if ((size & (WORD | LONG)) && (gulOutLoc & 1)) {
        gulOutLoc++;
        listLoc();
    }

    // Pass 1: Define the label, if any, attached to this directive
    // Pass 2: Verify the label, if any, is already defined

    if (*label)
        define(label, gulOutLoc, gfPass2, errorPtr);

    // Check for the presence of the operand list

    if (!*op) {
        NEWERROR(*errorPtr, SYNTAX);
        return NORMAL;
    }

    //

    do {
        op = skipSpace(op);
        if (*op == '\'') {
            op = collect(++op, string);
            if (!isspace(*op) && *op != ',') {
                NEWERROR(*errorPtr, SYNTAX);
                return NORMAL;
            }

            p = string;
            while (*p) {
                outVal = *p++;
                if (size > BYTE)
                    outVal = (outVal << 8) + *p++;
                if (size > WORD) {
                    outVal = (outVal << 16) + (*p++ << 8);
                    outVal += *p++;
                }
                if (gfPass2)
                    output(outVal, size);
                gulOutLoc += size;
            }
        } else {
            op = eval(op, &outVal, &backRef, errorPtr);
            if (*errorPtr > SEVERE)
                return NORMAL;
            if (!isspace(*op) && *op != ',') {
                NEWERROR(*errorPtr, SYNTAX);
                return NORMAL;
            }
            if (gfPass2)
                output(outVal, size);
            gulOutLoc += size;
            if (size == BYTE && (outVal < -128 || outVal > 255)) {
                NEWERROR(*errorPtr, INV_8_BIT_DATA);
            } else if (size == WORD && (outVal < -32768 || outVal > 65535))
                NEWERROR(*errorPtr, INV_16_BIT_DATA);
        }
    } while (*op++ == ',');
    --op;

    if (!isspace(*op) && *op)
        NEWERROR(*errorPtr, SYNTAX);

    return NORMAL;
}

/**********************************************************************
 *
 *	Function collect parses strings for dc. Each output string
 *	is padded with four nulls at the end.
 *
 **********************************************************************/

char *collect(char *s, char *d)
{
    while (*s) {
        if (*s == '\'') {
            if (*(s+1) == '\'') {
                *d++ = *s;
                s += 2;
            } else {
                *d++ = '\0';
                *d++ = '\0';
                *d++ = '\0';
                *d++ = '\0';
                return ++s;
            }
        } else {
            *d++ = *s++;
        }
    }

    return s;
}


/***********************************************************************
 *
 *	Function dcb implements the DCB directive.
 *
 ***********************************************************************/

int dcb(int size, char *label, char *op, int *errorPtr)
{
    long    blockSize, blockVal, i;
    char backRef;

    if (size == SHORT) {
        NEWERROR(*errorPtr, INV_SIZE_CODE);
        size = WORD;
    } else if (!size)
        size = WORD;
    /* Move location counter to a word boundary and fix the listing if doing
       DCB.W or DCB.L (but not if doing DCB.B, so DCB.B's can be contiguous)
 */
    if ((size & (WORD | LONG)) && (gulOutLoc & 1)) {
        gulOutLoc++;
        listLoc();
    }
    /* Define the label attached to this directive, if any */
    if (*label)
        define(label, gulOutLoc, gfPass2, errorPtr);
    /* Evaluate the size of the block (in bytes, words, or longwords) */
    op = eval(op, &blockSize, &backRef, errorPtr);
    if (*errorPtr < SEVERE && !backRef) {
        NEWERROR(*errorPtr, INV_FORWARD_REF);
        return NORMAL;
    }
    if (*errorPtr > SEVERE)
        return NORMAL;
    if (*op != ',') {
        NEWERROR(*errorPtr, SYNTAX);
        return NORMAL;
    }
    if (blockSize < 0) {
        NEWERROR(*errorPtr, INV_LENGTH);
        return NORMAL;
    }
    /* Evaluate the data to put in block */
    op = eval(++op, &blockVal, &backRef, errorPtr);
    if (*errorPtr < SEVERE) {
        if (!isspace(*op) && *op) {
            NEWERROR(*errorPtr, SYNTAX);
            return NORMAL;
        }
        /* On pass 2, output the block of values directly
           to the object file (without putting them in the listing) */
        if (gfPass2)
            for (i = 0; i < blockSize; i++) {
                outputObj(gulOutLoc, blockVal, size);
                gulOutLoc += size;
            } else
            gulOutLoc += blockSize * size;
    }

    return NORMAL;
}


/***********************************************************************
 *
 *	Function ds implements the DS directive.
 *
 ***********************************************************************/

int ds(int size, char *label, char *op, int *errorPtr)
{
    long blockSize;
    char backRef;

    if (size == SHORT) {
        NEWERROR(*errorPtr, INV_SIZE_CODE);
        size = WORD;
    } else if (!size)
        size = WORD;

    /* Move location counter to a word boundary and fix the listing if doing
       DS.W or DS.L (but not if doing DS.B, so DS.B's can be contiguous) */

    if ((size & (WORD | LONG)) && (gulOutLoc & 1)) {
        gulOutLoc++;
        listLoc();
    }

    /* Define the label attached to this directive, if any */
    if (*label)
        define(label, gulOutLoc, gfPass2, errorPtr);

    /* Evaluate the size of the block (in bytes, words, or longwords) */
    op = eval(op, &blockSize, &backRef, errorPtr);
    if (*errorPtr < SEVERE && !backRef) {
        NEWERROR(*errorPtr, INV_FORWARD_REF);
        return NORMAL;
    }
    if (*errorPtr > SEVERE)
        return NORMAL;

    if (!isspace(*op) && *op) {
        NEWERROR(*errorPtr, SYNTAX);
        return NORMAL;
    }
    if (blockSize < 0) {
        NEWERROR(*errorPtr, INV_LENGTH);
        return NORMAL;
    }

    // Set uninitialized data to zeros.
    // OK, this seems strange but for now we're pooling 'uninitialized'
    // data in with the initialized data.

    if (gfPass2) {
        int iblock;

        for (iblock = 0; iblock < blockSize; iblock++)
            output(0, size);
    }
    gulOutLoc += blockSize * size;

    return NORMAL;
}


//
//
//

int CodeDirective(int size, char *label, char *op, int *errorPtr)
{
    if (size != 0)
        NEWERROR(   *errorPtr,    INV_SIZE_CODE);

    // Already in a code block? just return.

    if (gbt == kbtCode)
        return NORMAL;

    // Save away important state pertaining to the previous block

    EndBlock();

    gpbOutput = gpbCode;
    gulOutLoc = gulCodeLoc;
    gbt = kbtCode;
    return NORMAL;
}

//
//
//

int DataDirective(int size, char *label, char *op, int *errorPtr)
{
    if (size != 0)
        NEWERROR(*errorPtr, INV_SIZE_CODE);

    // Already in a data block? just return.

    if (gbt == kbtData)
        return NORMAL;

    // Save away important state pertaining to the previous block

    EndBlock();

    gpbOutput = gpbData;
    gulOutLoc = gulDataLoc;
    gbt = kbtData;
    return NORMAL;
}

//
//
//

int ResDirective(int size, char *label, char *op, int *errorPtr)
{
    char szT[80];
    char backRef;
    char *pch;
    FILE *pfil;

    if (size != 0)
        NEWERROR(*errorPtr, INV_SIZE_CODE);

    // Save away important state pertaining to the previous block

    EndBlock();

    // Parse the res directive's arguments

    op = skipSpace(op);
    op = eval(op, &gfcResType, &backRef, errorPtr);
    if (*errorPtr > SEVERE)
        return NORMAL;

    if (!isspace(*op) && *op != ',') {
        NEWERROR(*errorPtr, SYNTAX);
        return NORMAL;
    }
    op = skipSpace(++op);
    op = eval(op, &gidRes, &backRef, errorPtr);
    if (*errorPtr > SEVERE)
        return NORMAL;

    // Check for resource data filename.

    szT[0] = 0;
    if (*op == ',') {
        op = skipSpace(++op);

        if (*op == '"') {
            pch = szT;
            while (*++op != '"')
                *pch++ = *op;
            *pch++ = 0;
            op++;
        }

        pfil = fopen(szT, "rb");
        if (pfil == NULL || pfil == (FILE *)-1) {
            NEWERROR(*errorPtr, RESOURCE_OPEN_FAILED);
            return NORMAL;
        }

        gulResLoc = fread(gpbResource, 1, kcbResMax, pfil);
        if (gulResLoc == kcbResMax) {
            NEWERROR(*errorPtr, RESOURCE_TOO_BIG);
            return NORMAL;
        }
        fclose(pfil);

        AddResource(gfcResType, (unsigned short)gidRes, gpbResource,
                    gulResLoc, FALSE);

        gbt = kbtCode;
        gulOutLoc = gulCodeLoc;
        gpbOutput = gpbCode;
    } else {
        gbt = kbtResource;
        gulOutLoc = 0;
        gpbOutput = gpbResource;
    }

    if (gfDebugOutput)
        printf("0x%lx, %d, %s\n", gfcResType, gidRes, szT);

    gulResLoc = 0;
    return NORMAL;
}


int IsExisting(const char *pszDir, const char *pszFile)
{
    char szT[_MAX_PATH];
    FILE *pfilT;

    if (pszDir != NULL)
#ifndef unix
        sprintf(szT, "%s\\%s", pszDir, pszFile);
#else
        sprintf(szT, "%s/%s", pszDir, pszFile);
#endif
    else
        strcpy(szT, pszFile);

    pfilT = fopen(szT, "rb");
    if (pfilT == NULL || pfilT == (FILE *)-1)
        return FALSE;
    fclose(pfilT);
    return TRUE;
}

void TruncateDir(char *pszPath)
{
    char ch;
    char *pchDirEnd = pszPath;
    while ((ch = *pszPath) != 0) {
#ifndef unix
        if (ch == '\\')
#else
        if (ch == '/')
#endif
            pchDirEnd = pszPath;
        pszPath++;
    }

    *pchDirEnd = 0;
}

//
//
//

int IncludeDirective(int size, char *label, char *op, int *errorPtr)
{
    char szFile[_MAX_PATH], szT[_MAX_PATH], szSearchPath[300];
    char *pszT, *pszPilaInc;
    int cchT;

    if (size != 0)
        NEWERROR(*errorPtr, INV_SIZE_CODE);

    // Get the include filename.

    szFile[0] = 0;
    op = skipSpace(op);

    if (*op == '"') {
        char *pch = szFile;
        while (*++op != '"')
            *pch++ = *op;
        *pch++ = 0;
        op++;
    } else {
        NEWERROR(*errorPtr, SYNTAX);
        return NORMAL;
    }

    gpsseCur->iLineNum++;

    //
    // This is the sequence followed for locating an include file:
    //
    // 1. If the path is fully qualified, make sure it exists.
    //    If not found, fail.
    // 2. Relative to same directory as the including file
    // 3. Relative to current directory
    // 4. Relative to each directory on the PILAINC include path, in order
    // 5. Relative to the dir which contains Pila.exe
    // 6. Relative to <PilaDir>\..\inc

    // 1. If the path is fully qualified, make sure it exists.
    //    If not found, fail.

#ifndef unix
    cchT = strlen(szFile);
    if (cchT >= 2) {
        if (szFile[1] == ':' || (szFile[0] == '\\' && szFile[1] == '\\')) {

            // Path is fully qualified

            if (!IsExisting(NULL, szFile)) {
                NEWERROR(*errorPtr, INCLUDE_OPEN_FAILED);
                return NORMAL;
            }

            // Found the file

            goto lbPushIt;
        }
    }
#else
    cchT = strlen(szFile);
    if (szFile[0] == '/') {

        // Path is fully qualified

        if (!IsExisting(NULL, szFile)) {
            NEWERROR(*errorPtr, INCLUDE_OPEN_FAILED);
            return NORMAL;
        }

        // Found the file

        goto lbPushIt;
    }
#endif

    // 2. Relative to same directory as the including file

    strcpy(szT, gasse[gcsse - 1].szFile);
    TruncateDir(szT);
#ifndef unix
    sprintf(szSearchPath, "%s;", szT);
#else
    sprintf(szSearchPath, "%s:", szT);
#endif

    // 3. Relative to current directory

#ifndef unix
    strcat(szSearchPath, ".;");
#else
    strcat(szSearchPath, ".:");
#endif

    // 4. Relative to each directory on the PILAINC include path, in order

    pszPilaInc = getenv("PILAINC");
    if (pszPilaInc != NULL)
        sprintf(szSearchPath, "%s%s:", szSearchPath, pszPilaInc);

#ifndef unix
    // 5. Relative to the dir which contains Pila.exe
    // 6. Relative to <PilaDir>\..\inc
    GetModuleFileName(NULL, szT, sizeof(szT));
    TruncateDir(szT);
    sprintf(szSearchPath, "%s%s;%s\\..\\inc", szSearchPath, szT, szT);
#endif

#ifndef unix
    if (SearchPath(szSearchPath, szFile, NULL, sizeof(szFile), szFile,
            &pszT) == 0) {
        NEWERROR(*errorPtr, INCLUDE_OPEN_FAILED);
        return NORMAL;
    }
#else
    pszT = szSearchPath;
    pszT = strtok(pszT, ":");
    while (pszT != NULL) {
        if (IsExisting(pszT, szFile)) {
            break;
        }
        pszT = strtok(NULL, ":");
    }

    if (pszT == NULL) {
        NEWERROR(*errorPtr, INCLUDE_OPEN_FAILED);
        return NORMAL;
    }
#endif

lbPushIt:
    if (PushSourceFile(szFile, errorPtr) == NULL) {

        // PushSourceFile will set the ERROR if there is one

        return NORMAL;
    }

    gpsseCur->iLineNum--;

    if (gfDebugOutput)
        printf("include \"%s\"\n", szT);

    return NORMAL;
}


FILE *PushSourceFile(const char *pszNewSource, int *errorPtr)
{
    struct SourceStackEntry *psse;
    char szT[_MAX_PATH];

    if (gcsse == kcsseMax) {
        NEWERROR(*errorPtr, INCLUDE_NESTED_TOO_DEEP);
        return NULL;
    }

    psse = &gasse[gcsse];

    psse->pfil = fopen(pszNewSource, "r");
    if (psse->pfil == NULL || psse->pfil == (FILE *)-1) {
        if (errorPtr != NULL)
            NEWERROR(*errorPtr, INCLUDE_OPEN_FAILED);
        return NULL;
    }

#ifndef unix
    GetFullPathName(pszNewSource, sizeof(szT), szT, NULL);
#else
    strcpy(szT, pszNewSource);
#endif

    strcpy(psse->szFile, szT);
    psse->iLineNum = 1;
    gpsseCur = psse;
    gcsse++;

    return gpsseCur->pfil;
}

int PopSourceFile()
{
    if (--gcsse <= 0)
        return FALSE;

    // Close the include file.

    fclose(gpsseCur->pfil);

    // NOTE: This will underflow when the last file (the main source file) is
    // popped but that's OK because it isn't used after that (better not be).

    gpsseCur = &gasse[gcsse - 1];

    return TRUE;
}

//
// Handler for the "appl" directive
//

int ApplDirective(int size, char *label, char *op, int *errorPtr)
{
    extern char gszAppName[_MAX_PATH];
    extern FourCC gfcAppId;
    char backRef;

    if (size != 0)
        NEWERROR(*errorPtr, INV_SIZE_CODE);

    // Get the application name.

    gszAppName[0] = 0;
    op = skipSpace(op);

    if (*op == '"') {
        char *pch = gszAppName;
        while (*++op != '"')
            *pch++ = *op;
        *pch++ = 0;
        op++;
    } else {
        NEWERROR(*errorPtr, SYNTAX);
        return NORMAL;
    }

    strcpy(gszAppName, gszAppName);

    // Get the application id -- NOT OPTIONAL

    if (!isspace(*op) && *op != ',') {
        NEWERROR(*errorPtr, SYNTAX);
        return NORMAL;
    }
    op = skipSpace(++op);
    op = eval(op, &gfcAppId, &backRef, errorPtr);

    return NORMAL;
}

//
// Handler for the "align" directive
//

int AlignDirective(int size, char *label, char *op, int *errorPtr)
{
    long nAlign;
    char backRef;

    if (size)
        NEWERROR(*errorPtr, INV_SIZE_CODE);
    if (!*op) {
        NEWERROR(*errorPtr, SYNTAX);
        return NORMAL;
    }
    op = eval(op, &nAlign, &backRef, errorPtr);
    if (*errorPtr < SEVERE && !backRef) {
        NEWERROR(*errorPtr, INV_FORWARD_REF);
    } else if (*errorPtr < ERROR_RANGE) {
        if (isspace(*op) || !*op) {

            // Align the output location

            gulOutLoc += nAlign - 1;
            gulOutLoc -= gulOutLoc % nAlign;

            // Define the label attached to this directive, if any

            if (*label != 0)
                define(label, gulOutLoc, gfPass2, errorPtr);

            // Show new location counter on listing

            listLoc();
        } else
            NEWERROR(*errorPtr, SYNTAX);
    }

    return NORMAL;
}

//
// Handler for the "list" directive
//

int ListDirective(int size, char *label, char *op, int *errorPtr)
{
    long fOn;
    char backRef;

    if (size)
        NEWERROR(*errorPtr, INV_SIZE_CODE);
    if (!*op) {
        NEWERROR(*errorPtr, SYNTAX);
        return NORMAL;
    }
    op = eval(op, &fOn, &backRef, errorPtr);
    if (*errorPtr < SEVERE && !backRef) {
        NEWERROR(*errorPtr, INV_FORWARD_REF);
    } else if (*errorPtr < ERROR_RANGE) {
        if (isspace(*op) || !*op) {
            if (gfListing)
                gfListOn = fOn;
        } else
            NEWERROR(*errorPtr, SYNTAX);
    }

    return NORMAL;
}
