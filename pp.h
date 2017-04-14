#ifndef __PP_H__
#define __PP_H__

typedef int16_t MDL;
#define mdlEOF 0
#define mdlNormalLine 1
#define mdlPseudoLine 2
#define mdlIgnoreLine 3

MDL MdlGetLine(char *sz, int16_t cchMax, FILE *pfile);


void InitSym();
void ClearSymContext();
int16_t FLookupSym(char *sz, int16_t *pw);
int16_t FLookupSymCb(char *sz, int16_t *pcb);

#endif /* __PP_H__ */
