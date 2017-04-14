/***********************************************************************
 *
 *		GLOBALS.C
 *		Global Variable Declarations for 68000 Assembler
 *
 *      Author: Paul McKee
 *		ECE492    North Carolina State University
 *
 *        Date:	12/13/86
 *
 ************************************************************************/


#include "pila.h"
#include "asm.h"


/* General */

long    gulOutLoc;      /* The assembler's location counter */
char    gfPass2;        /* Flag telling whether or not it's the second pass */
char    endFlag;        /* Flag set when the END directive is encountered */

/* File pointers */

FILE *gpfilList;        /* Listing file */

/* Listing information */

char line[256];         /* Source line */
int lineNum;            /* Source line number */
char *listPtr;          /* Pointer to buffer where a listing line is assembled */
char continuation;      /* TRUE if the listing line is a continuation */


/* Option flags with default values */

int gfListing = FALSE;  /* True if a listing is desired */
char cexFlag = FALSE;   /* True is Constants are to be EXpanded */


int errorCount, warningCount;   /* Number of errors and warnings */

//
//
//

BlockType gbt;
unsigned char *gpbCode;
long gulCodeLoc;

unsigned char *gpbData;
long gulDataLoc;

unsigned char *gpbResource;
long gulResLoc;
unsigned long gfcResType;
long gidRes;
long gcbResTotal;

unsigned char *gpbOutput;
