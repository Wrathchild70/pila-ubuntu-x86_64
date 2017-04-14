/***********************************************************************
 *
 *		CODE.C
 *		Code Generation Routines for 68000 Assembler
 *
 *    Function: output()
 *		Places the data whose size and value are specified onto
 *		the output stream at the current location contained in
 *		global varible gulOutLoc. That is, if a listing is being
 *		produced, it calls listObj() to print the data in the
 *		object code field of the current listing line; if an
 *		object file is being produced, it calls outputObj() to
 *		output the data in the form of S-records.
 *
 *		effAddr()
 *		Computes the 6-bit effective address code used by the
 *		68000 in most cases to specify address modes. This code
 *		is returned as the value of effAddr(). The desired
 *		addressing mode is determined by the field of the
 *		opDescriptor which is pointed to by the operand
 *		argument. The lower 3 bits of the output contain the
 *		register code and the upper 3 bits the mode code.
 *
 *		extWords()
 *		Computes and outputs (using output()) the extension
 *		words for the specified operand. The generated
 *		extension words are determined from the data contained
 *		in the opDescriptor pointed to by the op argument and
 *		from the size code of the instruction, passed in
 *		the size argument. The errorPtr argument is used to
 *		return an error code by the standard mechanism.
 *
 *	 Usage: output(data, size)
 *		int data, size;
 *
 *		effAddr(operand)
 *		opDescriptor *operand;
 *
 *		extWords(op, size, errorPtr)
 *		opDescriptor *op;
 *		int size, *errorPtr;
 *
 *      Author: Paul McKee
 *		ECE492    North Carolina State University
 *
 *        Date:	12/13/86
 *
 ************************************************************************/


#include "pila.h"
#include "asm.h"

extern long gulOutLoc;
extern char gfPass2;
extern FILE *gpfilList;

int output(long data, int size)
{
    if (gfListOn)
        listObj(data, size);

    outputObj(gulOutLoc, data, size);

    return NORMAL;
}


int effAddr(opDescriptor *operand)
{
    if (operand->mode == DnDirect)
        return 0x00 | operand->reg;

    if (operand->mode == AnDirect)
        return 0x08 | operand->reg;

    if (operand->mode == AnInd    )
        return 0x10 | operand->reg;

    if (operand->mode == AnIndPost)
        return 0x18 | operand->reg;

    if (operand->mode == AnIndPre)
        return 0x20 | operand->reg;

    if (operand->mode == AnIndDisp)
        return 0x28 | operand->reg;

    if (operand->mode == AnIndIndex)
        return 0x30 | operand->reg;

    if (operand->mode == AbsShort)
        return 0x38;

    if (operand->mode == AbsLong)
        return 0x39;

    if (operand->mode == PCDisp)
        return 0x3A;

    if (operand->mode == PCIndex)
        return 0x3B;

    if (operand->mode == Immediate)
        return 0x3C;

    printf("INVALID EFFECTIVE ADDRESSING MODE!\n");
    exit (0);
}


int extWords(opDescriptor *op, int size, int *errorPtr)
{
    long    disp;

    if (op->mode == DnDirect ||
        op->mode == AnDirect ||
        op->mode == AnInd ||
        op->mode == AnIndPost ||
        op->mode == AnIndPre) {;} else if (op->mode == AnIndDisp ||
                                           op->mode == PCDisp) {
        if (gfPass2) {
            disp = op->data;
            if (op->mode == PCDisp)
                disp -= gulOutLoc;
            output(disp & 0xFFFF, WORD);
            if (disp < -32768 || disp > 32767)
                NEWERROR(*errorPtr, INV_DISP);
        }
        gulOutLoc += 2;
    } else if (op->mode == AnIndIndex ||
               op->mode == PCIndex) {
        if (gfPass2) {
            disp = op->data;
            if (op->mode == PCIndex)
                disp -= gulOutLoc;
            output((( (int) (op->size) == LONG) ? 0x800 : 0)
                   | (op->index << 12) | (disp & 0xFF), WORD);
            if (disp < -128 || disp > 127)
                NEWERROR(*errorPtr, INV_DISP);
        }
        gulOutLoc += 2;
    } else if (op->mode == AbsShort) {
        if (gfPass2) {
            output(op->data & 0xFFFF, WORD);
            if (op->data < -32768 || op->data > 32767)
                NEWERROR(*errorPtr, INV_ABS_ADDRESS);
        }
        gulOutLoc += 2;
    } else if (op->mode == AbsLong) {
        if (gfPass2)
            output(op->data, LONG);
        gulOutLoc += 4;
    } else if (op->mode == Immediate) {
        if (!size || size == WORD) {
            if (gfPass2) {
                output(op->data & 0xFFFF, WORD);

                /*
                                        if (op->data < -32768 || op->data > 32767)
                                            NEWERROR(*errorPtr, INV_16_BIT_DATA);
                */
                if (op->data > 0xffff)
                    NEWERROR(*errorPtr, INV_16_BIT_DATA);
            }
            gulOutLoc += 2;
        } else if (size == BYTE) {
            if (gfPass2) {
                output(op->data & 0xFF, WORD);
                if (op->data < -32768 || op->data > 32767)
                    NEWERROR(*errorPtr, INV_8_BIT_DATA);
            }
            gulOutLoc += 2;
        } else if (size == LONG) {
            if (gfPass2)
                output(op->data, LONG);
            gulOutLoc += 4;
        }
    } else {
        printf("INVALID EFFECTIVE ADDRESSING MODE!\n");
        exit(0);
    }

    return NORMAL;
}
