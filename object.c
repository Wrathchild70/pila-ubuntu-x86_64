// object.c
//
// Author: Darrin Massena (darrin@massena.com)
// Date: 6/24/96


#include "pila.h"
#include "asm.h"
#include "prc.h"

int16_t outputObj(int32_t lOutLoc, int32_t data, int16_t size)
{
    unsigned char *pbOutput = gpbOutput + lOutLoc;
    switch (size) {
    case BYTE:
        *(unsigned char *)pbOutput = (unsigned char)data;
        break;

    case WORD:
        *(uint16_t *)pbOutput = SwapBytes((ushort)data);
        break;

    case LONG:
        *(uint32_t *)pbOutput = ReverseLong((uint32_t)data);
        break;
    }

    return NORMAL;
}
