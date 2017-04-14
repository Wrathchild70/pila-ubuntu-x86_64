#ifndef __UTIL_H__
#define __UTIL_H__

#include "std.h"


int16_t DxCalcExtent(unsigned char *sz, BOOL fBold);
int16_t DxCalcRgdx(unsigned char *sz, BOOL fBold, int16_t *rgdx);
VOID Error(char *sz);
VOID Error2(char *sz1, char *sz2);
void ErrorLine(char *sz);


void SwapBytes(void *pv, int16_t cb);
void SwapLong(void *pl);
void SwapStruct(void *pv, char *szPic);
VOID OpenOutput(char *szBase);
VOID CloseOutput();
void DumpBytes(void *pv, int16_t cb);
void PadWordBoundary();
int16_t IbOut();
VOID SetOutFileDir(char *sz);

extern char rgbZero[];
extern FILE *vfhIn;
extern FILE *vfhOut;

#endif /* __UTIL_H__ */
