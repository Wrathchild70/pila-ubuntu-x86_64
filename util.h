#ifndef __UTIL_H__
#define __UTIL_H__

#include "std.h"


int DxCalcExtent(unsigned char *sz, BOOL fBold);
int DxCalcRgdx(unsigned char *sz, BOOL fBold, int *rgdx);
VOID Error(char *sz);
VOID Error2(char *sz1, char *sz2);
void ErrorLine(char *sz);


void SwapBytes(void *pv, int cb);
void SwapLong(void *pl);
void SwapStruct(void *pv, char *szPic);
VOID OpenOutput(char *szBase);
VOID CloseOutput();
void DumpBytes(void *pv, int cb);
void PadWordBoundary();
int IbOut();
VOID SetOutFileDir(char *sz);

extern char rgbZero[];
extern FILE *vfhIn;
extern FILE *vfhOut;

#endif /* __UTIL_H__ */
