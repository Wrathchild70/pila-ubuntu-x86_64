// object.c
//
// Author: Darrin Massena (darrin@massena.com)
// Date: 6/24/96


#include "pila.h"
#include "asm.h"
#include "prc.h"

int outputObj(long lOutLoc, long data, int size)
{
    unsigned char *pbOutput = gpbOutput + lOutLoc;
    switch (size) {
    case BYTE:
        *(unsigned char *)pbOutput = (unsigned char)data;
        break;

    case WORD:
        *(unsigned short *)pbOutput = SwapBytes((unsigned short)data);
        break;

    case LONG:
        *(unsigned long *)pbOutput = ReverseLong((unsigned long)data);
        break;
    }

    return NORMAL;
}
