/***********************************************************************
 *
 *		ERROR.C
 *		Error message printer for 68000 Assembler
 *
 *    Function: printError()
 *		Prints an appropriate message to the specified output
 *		file according to the error code supplied. If the
 *		errorCode is OK, no message is printed; otherwise an
 *		WARNING or ERROR message is produced. The line number
 *		will be included in the message unless lineNum = -1.
 *
 *	 Usage:	printError(outFile, errorCode, lineNum)
 *		FILE *outFile;
 *		int errorCode, lineNum;
 *
 *      Author: Paul McKee
 *		ECE492    North Carolina State University
 *
 *        Date:	12/12/86
 *
 ************************************************************************/


#include "pila.h"
#include "asm.h"

extern FILE *gpfilList;     /* Listing file */

struct ErrPsz {
    int err;
    char *psz;
} gaerrpsz[] = {
    { SYNTAX, "Invalid syntax"},
    { UNDEFINED, "Undefined symbol"},
    { DIV_BY_ZERO, "Division by zero attempted"},
    { NUMBER_TOO_BIG, "Numeric constant exceeds 32 bits"},
    { ASCII_TOO_BIG, "ASCII constant exceeds 4 characters"},
    { INV_OPCODE, "Invalid opcode"},
    { INV_SIZE_CODE, "Invalid size code"},
    { INV_ADDR_MODE, "Invalid addressing mode"},
    { MULTIPLE_DEFS, "Symbol multiply defined"},
    { PHASE_ERROR, "Symbol value differs between first and second pass"},
    { INV_QUICK_CONST, "MOVEQ instruction constant out of range"},
    { INV_VECTOR_NUM, "Invalid vector number"},
    { INV_BRANCH_DISP, "Branch instruction displacement is out of range or invalid"},
    { LABEL_REQUIRED, "Label required with this directive"},
    { INV_DISP, "Displacement out of range"},
    { INV_ABS_ADDRESS, "Absolute address exceeds 16 bits"},
    { INV_8_BIT_DATA, "Immediate data exceeds 8 bits"},
    { INV_16_BIT_DATA, "Immediate data exceeds 16 bits"},
    { INCOMPLETE, "Evaluation of expression could not be completed"},
    { NOT_REG_LIST, "The symbol specified is not a register list symbol"},
    { REG_LIST_SPEC, "Register list symbol used in an expression"},
    { REG_LIST_UNDEF, "Register list symbol not previously defined"},
    { INV_SHIFT_COUNT, "Invalid constant shift count"},
    { INV_FORWARD_REF, "Forward references not allowed with this directive"},
    { INV_LENGTH, "Block length is less that zero"},
    { ODD_ADDRESS, "Origin value is odd (Location counter set to next highest address)"},
    { RESOURCE_OPEN_FAILED, "Failed to open resource file"},
    { RESOURCE_TOO_BIG, "Resource file too big"},
    { INCLUDE_OPEN_FAILED, "Failed to open include file"},
    { INCLUDE_NESTED_TOO_DEEP, "Include files nested too deep"},
};



int doprintError(FILE *outFile, char *pszError, char *pszWarnErr, int lineNum)
{
    if (lineNum >= 0)
        fprintf(outFile, "%s(%d) : %s: %s\n\n", gpsseCur->szFile, lineNum,
                pszWarnErr, pszError);
    else
        fprintf(outFile, "%s : %s: %s\n\n", gpsseCur->szFile, pszWarnErr, pszError);

    return NORMAL;
}



int printError(FILE *outFile, int errorCode, int lineNum)
{
    char *pszType, *pszError;
    int i;

    pszError = "No message defined";
    for (i = 0; i < sizeof(gaerrpsz) / sizeof(struct ErrPsz); i++) {
        if (gaerrpsz[i].err == errorCode) {
            pszError = gaerrpsz[i].psz;
            break;
        }
    }

    pszType = errorCode > ERROR_RANGE ? "error" : "warning";

    doprintError(outFile, pszError, pszType, lineNum);
    if (gfListing)
        doprintError(gpfilList, pszError, pszType, lineNum);
    return NORMAL;
}



void ErrorLine(char *sz)
{
    doprintError(stdout, sz, "error", gpsseCur->iLineNum);
    if (gfListing)
        doprintError(gpfilList, sz, "error", gpsseCur->iLineNum);
}

