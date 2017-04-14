/***********************************************************************
 *
 *		SYMBOL.C
 *		Symbol Handling Routines for 68000 Assembler
 *
 *    Function: lookup()
 *		Searches the symbol table for a previously defined
 *		symbol or creates a new symbol. The routine functions
 *		as follows:
 *
 *		Symbol
 *		Found				  Returned
 *		In	Create	  Action	  Error
 *		Table?  Flag	  Taken		  Code
 *		------  ------    --------------  -----------
 *		  N     FALSE     None		  UNDEFINED
 *		  N     TRUE      Symbol created  OK
 *		  Y     FALSE     None		  OK
 *		  Y	TRUE      None		  MULTIPLE_DEFS
 *
 *		In addition, the routine always returns a pointer to
 *		the structure (type symbolDef) that which contains the
 *		symbol that was found or created. The routine uses a
 *		hash function to index into an array of pointers to
 *		ordered linked lists of symbol definitions.
 *
 *		define()
 *		Defines the symbol whose name is specified to have the
 *		value specified. If check is TRUE, then the symbol is
 *		assumed to already exist and its value is checked
 *		against the passed value; a PHASE_ERROR results if the
 *		values are not the same. When check is TRUE the routine
 *		also sets the backRef bit for the symbol. If check is
 *		FALSE, then the symbol is defined and its value is set
 *		equal to the supplied number. The function returns a
 *		pointer to the symbol definition structure.
 *
 *	 Usage:	symbolDef *lookup(sym, create, errorPtr)
 *		char *sym;
 *		int create, *errorPtr;
 *
 *	 	symbolDef *define(sym, value, check, errorPtr)
 *		char *sym;
 *		int value, check, *errorPtr;
 *
 *      Author: Paul McKee
 *		ECE492    North Carolina State University
 *
 *        Date:	11/28/86
 *
 ************************************************************************/


#include "pila.h"
#include "asm.h"

/* MAXHASH is the range of the hash function. hash()
   returns values from 0 to MAXHASH inclusive. */

#define MAXHASH 26

static symbolDef *htable[MAXHASH+1];


symbolDef *lookup(char *sym, int create, int *errorPtr)
{
    int h, cmp;
    symbolDef *s, *last, *t;
    static char initialized = FALSE;

    if (!initialized) {
        for (h = 0; h <= MAXHASH; h++)
            htable[h] = 0;
        initialized = TRUE;
    }

    h = hash(sym);
    if (s = htable[h]) {

        /* Search the linked list for a matching symbol */

        last = NULL;
        while (s && (cmp = strcmp(s->name, sym)) < 0) {
            last = s;
            s = s->next;
        }

        /* If a match was found, return pointer to the structure */

        if (s && !cmp) {
            if (create)
                NEWERROR(*errorPtr, MULTIPLE_DEFS);
            t = s;
        }

        /* Otherwise insert the symbol in the list */

        else if (create) {
            t = (symbolDef *) malloc(sizeof(symbolDef));
            strcpy(t->name, sym);

            if (last) {

                /* The symbol goes after an existing symbol */

                last->next = t;
                t->next = s;
            } else {

                /* The symbol goes at the head of a list */

                t->next = htable[h];
                htable[h] = t;
            }
        } else {
            NEWERROR(*errorPtr, UNDEFINED);
        }

    } else if (create) {
        t = (symbolDef *) malloc(sizeof(symbolDef));
        htable[h] = t;
        t->next = NULL;
        strcpy(t->name, sym);

    } else {
        NEWERROR(*errorPtr, UNDEFINED);
    }
    return t;
}


int hash(char *symbol)
{
    short sum = 0;
    while (*symbol) {
        sum += (isupper(*symbol)) ? (*symbol - 'A') : 26;
        symbol++;
    }

    return sum % (short)27;
}


symbolDef *define(char *sym, long value, int check, int *errorPtr)
{
    symbolDef *symbol;

    symbol = lookup(sym, !check, errorPtr);
    if (*errorPtr < ERROR_RANGE) {
        if (check) {
            if (symbol->value != value)
                NEWERROR(*errorPtr, PHASE_ERROR);
            symbol->flags |= kfSymBackRef;
            if (gfDebugOutput)
                printf("Marking symbol \"%s\"\n", sym);
        } else {
            if (gfDebugOutput)
                printf("Defining the symbol \"%s\" as %08lX.\n", sym, value);
            symbol->value = value;

            switch (gbt) {
            case kbtCode:
                symbol->flags = kfSymCode;
                break;

            case kbtData:
                symbol->flags = kfSymData;
                break;

            case kbtResource:
                symbol->flags = kfSymResource;
                break;

            default:
                printf("Unknown block type!\n");
                exit(0);
            }
        }
    }
    return symbol;
}
