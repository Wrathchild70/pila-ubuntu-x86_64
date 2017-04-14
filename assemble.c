/***********************************************************************
 *
 *		ASSEMBLE.C
 *		Assembly Routines for 68000 Assembler
 *
 *    Function: processFile()
 *		Assembles the input file. For each pass, the function
 *		passes each line of the input file to assemble() to be
 *		assembled. The routine also makes sure that errors are
 *		printed on the screen and listed in the listing file
 *		and keeps track of the error counts and the line
 *		number.
 *
 *		assemble()
 *		Assembles one line of assembly code. The line argument
 *		points to the line to be assembled, and the errorPtr
 *		argument is used to return an error code via the
 *		standard mechanism. The routine first determines if the
 *		line contains a label and saves the label for later
 *		use. It then calls instLookup() to look up the
 *		instruction (or directive) in the instruction table. If
 *		this search is successful and the parseFlag for that
 *		instruction is TRUE, it defines the label and parses
 *		the source and destination operands of the instruction
 *		(if appropriate) and searches the flavor list for the
 *		instruction, calling the proper routine if a match is
 *		found. If parseFlag is FALSE, it passes pointers to the
 *		label and operands to the specified routine for
 *		processing.
 *
 *	 Usage: processFile()
 *
 *		assemble(line, errorPtr)
 *		char *line;
 *		int *errorPtr;
 *
 *      Author: Paul McKee
 *		ECE492    North Carolina State University
 *
 *        Date:	12/13/86
 *
 ************************************************************************/

#include "pila.h"
#include "asm.h"

#include "std.h"
#include "util.h"
#include "lex.h"
#include "pp.h"


extern long gulOutLoc;      /* The assembler's location counter */
extern char gfPass2;        /* Flag set during second pass */
extern char endFlag;        /* Flag set when the END directive is encountered */
extern char continuation;   /* TRUE if the listing line is a continuation */

extern int errorCount, warningCount;

extern char line[256];      /* Source line */
extern FILE *gpfilList;     /* Listing file */

int processFile(char *szFile)
{
    char capLine[256];
    int error;
    char pass;
    MDL mdl;
    FILE *pfilInput;


    // Allocate temporary buffers used for code, data, and resources.

    gpbCode = (unsigned char *)malloc(kcbCodeMax);
    gpbData = (unsigned char *)malloc(kcbDataMax);
    gpbResource = (unsigned char *)malloc(kcbResMax);

    if (gpbCode == NULL || gpbData == NULL || gpbResource == NULL) {
        printf("Failed to allocate necessary assembly buffers!\n");
        exit(0);
    }

    //

    gfPass2 = FALSE;
    for (pass = 0; pass < 2; pass++) {
        gulOutLoc = gulCodeLoc = gulDataLoc = gulResLoc = 0;

        gbt = kbtCode;      // block is code unless otherwise specified
        gpbOutput = gpbCode;

        pfilInput = PushSourceFile(szFile, NULL);
        if (pfilInput == NULL || pfilInput == (FILE *)-1) {
            fputs("Input file not found\n", stdout);
            exit(0);
        }

        //gpsseCur->iLineNum = 1;
        endFlag = FALSE;
        errorCount = warningCount = 0;

        do {
            while ((mdl = MdlGetLine(line, 256, gpsseCur->pfil)) != mdlEOF) {
                strcap(capLine, line);
                error = OK;
                continuation = FALSE;
                if (gfPass2 && gfListOn)
                    listLoc();
                if (mdl != mdlIgnoreLine)
                    assemble(capLine, &error);
                if (gfPass2) {
                    if (error > MINOR)
                        errorCount++;
                    else if (error > WARNING)
                        warningCount++;
                    if (gfListOn)
                        listLine();
                    if (error != OK) {
                        printf(line);
                        printError(stdout, error, gpsseCur->iLineNum);
                        if (gfListing)
                            printError(gpfilList, error, -1);
                    }
                }
                if (mdl != mdlPseudoLine)
                    gpsseCur->iLineNum++;
            }
        } while (PopSourceFile());

        if (!gfPass2) {
            gfPass2 = TRUE;
        }
    }

    return NORMAL;
}


int assemble(char *line, int *errorPtr)
{
    instruction *tablePtr;
    flavor *flavorPtr;
    opDescriptor source, dest;
    char *p, *start, label[SIGCHARS+1], size, f, sourceParsed, destParsed;
    unsigned short mask, i;

    p = start = skipSpace(line);

    // Comments start with '*' or ';'

    if (*p && *p != '*' &&  *p != ';') {

        // Get a word (alphanum string including '.', '_', '$', '?', '@')
        // May be a label or instruction

        i = 0;
        do {
            if (i < SIGCHARS)
                label[i++] = *p;
            p++;
        } while (isalnum(*p) || *p == '.' || *p == '_' || *p == '$' ||
                 *p == '?' || *p == '@');
        label[i] = '\0';

        // Is this a label? (must be at the start of a line and end in a colon)

        if ((isspace(*p) && start == line) || *p == ':') {
            if (*p == ':')
                p++;
            p = skipSpace(p);

            // Look for a comment again.

            if (*p == '*' || *p == ';' || !*p) {
                define(label, gulOutLoc, gfPass2, errorPtr);
                return NORMAL;
            }
        } else {

            // Not a label, reset to start of line to begin getting the 
            // instruction.

            p = start;
            label[0] = '\0';
        }

        // Parse an instruction

        p = instLookup(p, &tablePtr, &size, errorPtr);
        if (*errorPtr > SEVERE)
            return NORMAL;

        // Parse the instruction's operands

        p = skipSpace(p);
        if (tablePtr->parseFlag) {

            /* Move location counter to a word boundary and fix
               the listing before assembling an instruction */

            if (gulOutLoc & 1) {
                gulOutLoc++;
                listLoc();
            }
            if (*label)
                define(label, gulOutLoc, gfPass2, errorPtr);

            if (*errorPtr > SEVERE)
                return NORMAL;

            sourceParsed = destParsed = FALSE;
            flavorPtr = tablePtr->flavorPtr;
            for (f = 0; (f < tablePtr->flavorCount); f++, flavorPtr++) {
                if (!sourceParsed && flavorPtr->source) {
                    p = opParse(p, &source, errorPtr);
                    if (*errorPtr > SEVERE)
                        return NORMAL;
                    sourceParsed = TRUE;
                }

                if (!destParsed && flavorPtr->dest) {
                    if (*p != ',') {
                        NEWERROR(*errorPtr, SYNTAX);
                        return NORMAL;
                    }

                    p = skipSpace(p + 1);

                    p = opParse(p, &dest, errorPtr);
                    if (*errorPtr > SEVERE)
                        return NORMAL;

                    if (!isspace(*p) && *p) {
                        NEWERROR(*errorPtr, SYNTAX);
                        return NORMAL;
                    }
                    destParsed = TRUE;
                }

                if (!flavorPtr->source) {
                    mask = pickMask( (int) size, flavorPtr, errorPtr);
                    (*flavorPtr->exec)(mask, (int) size, &source, &dest, errorPtr);
                    return NORMAL;
                } else if ((source.mode & flavorPtr->source) && !flavorPtr->dest) {
                    if (!isspace(*p) && *p) {
                        NEWERROR(*errorPtr, SYNTAX);
                        return NORMAL;
                    }
                    mask = pickMask( (int) size, flavorPtr, errorPtr);
                    (*flavorPtr->exec)(mask, (int) size, &source, &dest, errorPtr);
                    return NORMAL;
                } else if (source.mode & flavorPtr->source &&
                           dest.mode & flavorPtr->dest) {
                    mask = pickMask( (int) size, flavorPtr, errorPtr);
                    (*flavorPtr->exec)(mask, (int) size, &source, &dest, errorPtr);
                    return NORMAL;
                }
            }
            NEWERROR(*errorPtr, INV_ADDR_MODE);
        } else {
            (*tablePtr->exec)( (int) size, label, p, errorPtr);
            return NORMAL;
        }
    }

    return NORMAL;
}


int pickMask(int size, flavor *flavorPtr, int *errorPtr)
{
    if (!size || size & flavorPtr->sizes)
        if (size & (BYTE | SHORT))
            return flavorPtr->bytemask;
        else if (!size || size == WORD)
            return flavorPtr->wordmask;
        else
            return flavorPtr->longmask;
    NEWERROR(*errorPtr, INV_SIZE_CODE);
    return flavorPtr->wordmask;
}
