// PRC.h
//
// Data structures, constants, macros and prototypes used by PRC.c and the
// callers of the functions it contains.
//
// Author: Darrin Massena (darrin@massena.com)
// Date: 6/24/96

#ifndef __PRC_H__
#define __PRC_H__

typedef unsigned char byte;     // b
typedef unsigned short ushort;  // us
typedef unsigned long ulong;    // ul
typedef int bool;               // f
typedef ulong FourCC;           // fc

#ifndef TRUE
    #define TRUE	((bool)1)
#endif

#ifndef FALSE
    #define FALSE	((bool)0)
#endif

#ifndef NULL
    #define NULL	0
#endif

#define SwapWords(ul)	(ulong)((((ulong)(ul)) >> 16) | (((ulong)(ul)) << 16))
#define SwapBytes(us)	(ushort)((((ushort)(us)) >> 8) | (((ushort)(us)) << 8))
#define SwapLong(ul)	SwapWords(ul)
#define SwapShort(us)	SwapBytes(us)
#define ReverseLong(ul)	(ulong)((((ulong)(ul)) >> 24) | (((ulong)(ul)) << 24) | ((((ulong)(ul)) & 0x00FF0000) >> 8) | ((ul & 0x0000FF00) << 8))

typedef struct _ResourceMapEntry { // rme
    FourCC fcType;
    ushort usId;
    byte *pbData;
    ulong cbData;
} ResourceMapEntry;

bool AddResource(FourCC fcType, ushort usId, byte *pbData, ulong cbData,
                 bool fHead);
long WritePrc(char *pszFileName, char *pszAppName, byte *pbCode, long cbCode,
              byte *pbData, long cbData);

#endif // ndef __PRC_H__
