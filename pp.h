#ifndef __PP_H__
#define __PP_H__

typedef int MDL;
#define mdlEOF 0
#define mdlNormalLine 1
#define mdlPseudoLine 2
#define mdlIgnoreLine 3

MDL MdlGetLine(char *sz, int cchMax, FILE *pfile);


void InitSym();
void ClearSymContext();
int FLookupSym(char *sz, int *pw);
int FLookupSymCb(char *sz, int *pcb);

#endif /* __PP_H__ */
