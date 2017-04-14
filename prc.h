// PRC.h
//
// Data structures, constants, macros and prototypes used by PRC.c and the
// callers of the functions it contains.
//
// Author: Darrin Massena (darrin@massena.com)
// Date: 6/24/96

#ifndef __PRC_H__
#define __PRC_H__

#include <stdint.h>

typedef unsigned char byte;     // b
typedef int16_t BOOL;               // f
typedef uint32_t FourCC;           // fc

#ifndef TRUE
    #define TRUE	((BOOL)1)
#endif

#ifndef FALSE
    #define FALSE	((BOOL)0)
#endif

#ifndef NULL
    #define NULL	0
#endif

#define SwapWords(ul)	(uint32_t)((((uint32_t)(ul)) >> 16) | (((uint32_t)(ul)) << 16))
#define SwapBytes(us)	(ushort)((((ushort)(us)) >> 8) | (((ushort)(us)) << 8))
#define SwapLong(ul)	SwapWords(ul)
#define SwapShort(us)	SwapBytes(us)
#define ReverseLong(ul)	(uint32_t)((((uint32_t)(ul)) >> 24) | (((uint32_t)(ul)) << 24) | ((((uint32_t)(ul)) & 0x00FF0000) >> 8) | ((ul & 0x0000FF00) << 8))

typedef struct _ResourceMapEntry { // rme
    FourCC fcType;
    uint16_t usId;
    byte *pbData;
    uint32_t cbData;
} ResourceMapEntry;

BOOL AddResource(FourCC fcType, uint16_t usId, byte *pbData, uint32_t cbData,
                 BOOL fHead);
int32_t WritePrc(char *pszFileName, char *pszAppName, byte *pbCode, int32_t cbCode,
              byte *pbData, int32_t cbData);

#endif // ndef __PRC_H__
