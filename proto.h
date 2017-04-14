/***********************************************************************
 *
 *		PROTO.H
 *		Global Definitions for 68000 Assembler
 *
 *      Author: Paul McKee
 *		ECE492    North Carolina State University
 *
 *        Date:	9/5/88
 *
 ************************************************************************/

#ifndef __PROTO_H__
#define __PROTO_H__


/* ANSI C function prototype definitions */

int16_t processFile(char *);

int16_t assemble(char *, int16_t *);

int16_t pickMask(int16_t, flavor *, int16_t *);

int16_t move(int16_t, int16_t, opDescriptor *, opDescriptor *, int16_t *);

int16_t zeroOp(int16_t, int16_t, opDescriptor *, opDescriptor *, int16_t *);

int16_t oneOp(int16_t, int16_t, opDescriptor *, opDescriptor *, int16_t *);

int16_t arithReg(int16_t, int16_t, opDescriptor *, opDescriptor *, int16_t *);

int16_t arithAddr(int16_t, int16_t, opDescriptor *, opDescriptor *, int16_t *);

int16_t immedInst(int16_t, int16_t, opDescriptor *, opDescriptor *, int16_t *);

int16_t quickMath(int16_t, int16_t, opDescriptor *, opDescriptor *, int16_t *);

int16_t movep(int16_t, int16_t, opDescriptor *, opDescriptor *, int16_t *);

int16_t moves(int16_t, int16_t, opDescriptor *, opDescriptor *, int16_t *);

int16_t moveReg(int16_t, int16_t, opDescriptor *, opDescriptor *, int16_t *);

int16_t staticBit(int16_t, int16_t, opDescriptor *, opDescriptor *, int16_t *);

int16_t movec(int16_t, int16_t, opDescriptor *, opDescriptor *, int16_t *);

int16_t trap(int16_t, int16_t, opDescriptor *, opDescriptor *, int16_t *);

int16_t branch(int16_t, int16_t, opDescriptor *, opDescriptor *, int16_t *);

int16_t moveq(int16_t, int16_t, opDescriptor *, opDescriptor *, int16_t *);

int16_t immedToCCR(int16_t, int16_t, opDescriptor *, opDescriptor *, int16_t *);

int16_t immedWord(int16_t, int16_t, opDescriptor *, opDescriptor *, int16_t *);

int16_t dbcc(int16_t, int16_t, opDescriptor *, opDescriptor *, int16_t *);

int16_t scc(int16_t, int16_t, opDescriptor *, opDescriptor *, int16_t *);

int16_t shiftReg(int16_t, int16_t, opDescriptor *, opDescriptor *, int16_t *);

int16_t exg(int16_t, int16_t, opDescriptor *, opDescriptor *, int16_t *);

int16_t twoReg(int16_t, int16_t, opDescriptor *, opDescriptor *, int16_t *);

int16_t oneReg(int16_t, int16_t, opDescriptor *, opDescriptor *, int16_t *);

int16_t moveUSP(int16_t, int16_t, opDescriptor *, opDescriptor *, int16_t *);

int16_t link(int16_t, int16_t, opDescriptor *, opDescriptor *, int16_t *);

int16_t output(int32_t, int16_t);

int16_t effAddr(opDescriptor *);

int16_t extWords(opDescriptor *, int16_t, int16_t *);

#ifdef ORG_DIRECTIVE
int16_t org(int16_t, char *, char *, int16_t *);
#endif

int16_t funct_end(int16_t, char *, char *, int16_t *);

int16_t equ(int16_t, char *, char *, int16_t *);

int16_t set(int16_t, char *, char *, int16_t *);

int16_t dc(int16_t, char *, char *, int16_t *);

char *collect(char *, char *);

int16_t dcb(int16_t, char *, char *, int16_t *);

int16_t ds(int16_t, char *, char *, int16_t *);

int16_t printError(FILE *, int16_t, int16_t);

char *eval(char *, int32_t *, char *, int16_t *);

char *evalNumber(char *, int32_t *, char *, int16_t *);

int16_t precedence(char);

int16_t doOp(int32_t, int32_t, char, int32_t *);

char *instLookup(char *, instruction *(*), char *, int16_t *);

int16_t initList(char *);

int16_t listLine(void);

int16_t listLoc(void);

int16_t listObj(int32_t, int16_t);

int16_t main(int16_t, char *[]);

int16_t strcap(char *, char *);

char *skipSpace(char *);

int16_t getopt(int16_t, char *[], char *, int16_t *);

int16_t help(void);

int16_t movem(int16_t, char *, char *, int16_t *);

int16_t reg(int16_t, char *, char *, int16_t *);

char *evalList(char *, uint16_t *, int16_t *);

int16_t initObj(char *);

int16_t outputObj(int32_t, int32_t, int16_t);

int32_t checkValue(int32_t);

int16_t finishObj(void);

char *opParse(char *, opDescriptor *, int16_t *);

symbolDef *lookup(char *, int16_t, int16_t *);

int16_t hash(char *);

symbolDef *define(char *, int32_t, int16_t, int16_t *);

int16_t writeObj(void);

int16_t CodeDirective(int16_t size, char *label, char *op, int16_t *errorPtr);
int16_t DataDirective(int16_t size, char *label, char *op, int16_t *errorPtr);
int16_t ResDirective(int16_t size, char *label, char *op, int16_t *errorPtr);
int16_t IncludeDirective(int16_t size, char *label, char *op, int16_t *errorPtr);
int16_t ApplDirective(int16_t size, char *label, char *op, int16_t *errorPtr);
FILE *PushSourceFile(const char *pszSourcePath, const char *pszNewSource, int16_t *errorPtr);
int16_t PopSourceFile();
int16_t AlignDirective(int16_t size, char *label, char *op, int16_t *errorPtr);
int16_t ListDirective(int16_t size, char *label, char *op, int16_t *errorPtr);

#endif /* __PROTO_H__ */
