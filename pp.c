/*-------------------------------------------------------------------
| pp.c
|
|	This started out as a preprocessor for pila, but has grown into
|	a lot more.  It now supports structs, globals, locals, proc
|	definitions, calls, traps and libtraps
|
|	wesc@ricochet.net
--------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "std.h"
#include "util.h"
#include "lex.h"
#include "pp.h"

#ifdef unix
#define stricmp strcasecmp
#endif

extern char gfPass2;


// Emitted Line
typedef struct _el {
    char sz[256];
    struct _el *pelNext;
} EL;

EL *pelCur;
EL *pelFirst;


// SYMbol.  This is a symbol table entry.  It may be either a local,
// global or type or struct.  If it is a struct then pmemFirst points to the
// first member of the struct.  The cb field indicates the size of the
// type, but is only valid for leaf node types such as .b, .w and .l or the
// hack constant types which are added for .nnn structure members or locals.
typedef struct _sym {
    char *sz;
    union {
        int cb;
        int ib;
    } u;
    BOOL fGlobal;
    BOOL fType;
    struct _sym *psymType;
    struct _mem *pmemFirst;
    struct _sym *psymNext;
} SYM;

// MEMber -- a member in a struct.
typedef struct _mem {
    char *sz;
    SYM *psymType;
    struct _mem *pmemNext;
} MEM;

SYM *psymTypeFirst;

SYM *psymLocalFirst;
SYM *psymArgFirst;
SYM *psymGlobalFirst;


// ReservedWord
typedef enum {
    rwCall,
    rwSysTrap,
    rwSysLibTrap,
    rwProc,
    rwLocal,
    rwGlobal,
    rwBeginProc,
    rwEndProc,
    rwStruct,
    rwEndStruct,
    rwSizeof,
    rwByte,
    rwWord,
    rwLong,
    rwA0, rwA1, rwA2, rwA3, rwA4, rwA5, rwA6, rwA7,
    rwD0, rwD1, rwD2, rwD3, rwD4, rwD5, rwD6, rwD7,
    rwNil} RW;



typedef struct _rwt {
    char *sz1;
    RW rw;
} RWT;

// could just use index into this table as rw but that is kinda fragile.
RWT rgrwt[] =
{
    {"call", rwCall},
    {"systrap", rwSysTrap},
    {"syslibtrap", rwSysLibTrap},
    {"proc", rwProc},
    {"local", rwLocal},
    {"global", rwGlobal},
    {"beginproc", rwBeginProc},
    {"endproc", rwEndProc},
    {"struct", rwStruct},
    {"endstruct", rwEndStruct},
    {"sizeof", rwSizeof},
    {"b", rwByte},
    {"w", rwWord},
    {"l", rwLong},
    {"a0", rwA0},
    {"a1", rwA1},
    {"a2", rwA2},
    {"a3", rwA3},
    {"a4", rwA4},
    {"a5", rwA5},
    {"a6", rwA6},
    {"a7", rwA7},
    {"d0", rwD0},
    {"d1", rwD1},
    {"d2", rwD2},
    {"d3", rwD3},
    {"d4", rwD4},
    {"d5", rwD5},
    {"d6", rwD6},
    {"d7", rwD7},
    {NULL, rwNil},
};


char *PchFromRw(int rw)
{
    RWT *prwt;

    prwt = rgrwt;
    while (prwt->sz1 != NULL) {
        if (prwt->rw == rw) {
            return prwt->sz1;
        }
        prwt++;
    }
    return NULL;
}



RW RwFromLex(LEX *plex)
{
    RWT *prwt;

    if (plex->lt != ltId)
        return rwNil;
    prwt = rgrwt;
    while (prwt->sz1 != NULL) {
        if (stricmp(plex->szId, prwt->sz1) == 0)
            return prwt->rw;
        prwt++;
    }
    return rwNil;
}


typedef struct _tok {
    RW rw;
    LEX lex;
} TOK;


BOOL fTokUngotten;
TOK tokPrev;
TOK tok;


BOOL FGetTok(TOK *ptok)
{
    if (fTokUngotten) {
        *ptok = tokPrev;
        fTokUngotten = fFalse;
        return fTrue;
    }

    ptok->rw = rwNil;
    if (!FGetLex(&ptok->lex))
        return fFalse;
    if (ptok->lex.lt == ltId)
        ptok->rw = RwFromLex(&ptok->lex);
    tokPrev = *ptok;
    return fTrue;
}

VOID EmitSz(char *sz)
{
    if (pelCur == NULL)
        pelCur = calloc(1, sizeof(EL));
    strcat(pelCur->sz, sz);
    if (strchr(pelCur->sz, '\n')) {
        EL *pel;
        EL *pelPrev;
        pelPrev = NULL;
        for (pel = pelFirst; pel != NULL; pel = pel->pelNext) {
            pelPrev = pel;
        }
        if (pelPrev == NULL)
            pelFirst = pelCur;
        else
            pelPrev->pelNext = pelCur;
        pelCur = NULL;
    }
}

VOID EmitSz2(char *sz1, char *sz2)
{
    EmitSz(sz1);
    EmitSz(sz2);
}

VOID EmitInst(char *szInst, char *szOp1, char *szOp2)
{
    EmitSz("\t");
    EmitSz(szInst);
    EmitSz("\t");
    if (szOp1 != NULL) {
        EmitSz(szOp1);
    }
    if (szOp2 != NULL) {
        EmitSz(",");
        EmitSz(szOp2);
    }
    EmitSz("\n");
}

VOID EmitW(int w)
{
    char szT[16];

    sprintf(szT, "%d", w);
    EmitSz(szT);
}


VOID UngetTok()
{
    tok = tokPrev;
    fTokUngotten = fTrue;
}


BOOL FGetExpectLt(TOK *ptok, LT lt, char *szErr)
{
    FGetTok(ptok);
    if (ptok->lex.lt != lt) {
        if (szErr == NULL) {
            if (lt == ltId)
                ErrorLine("Syntax error : expecting identifier");
            else if (lt == ltStr)
                ErrorLine("Syntax error : expecting string");
            else if (lt == ltConst)
                ErrorLine("Syntax error : expecting constant");
            else
                ErrorLine("syntax error");
        } else {
            char szT[128];
            sprintf(szT, "expecting: %s", szErr);
            ErrorLine(szT);
        }
        return fFalse;
    }
    return fTrue;
}

BOOL FGetExpectRw(RW rw)
{
    TOK tok;

    FGetTok(&tok);
    if (tok.rw != rw) {
        char szErr[64];
        sprintf(szErr, "%s expected", PchFromRw(rw));
        ErrorLine(szErr);
        return fFalse;
    }
    return fTrue;
}





SYM *PsymAdd(SYM **ppsymFirst, char *sz, int cb)
{
    SYM *psym;

    psym = calloc(1, sizeof(SYM));
    psym->sz = strdup(sz);
    psym->u.cb = cb;
    psym->psymNext = *ppsymFirst;
    *ppsymFirst = psym;
    return psym;
}

SYM *PsymAddType(char *sz, int cb)
{
    SYM *psym;

    psym = PsymAdd(&psymTypeFirst, sz, cb);
    if (psym != NULL)
        psym->fType =  fTrue;
    return psym;
}

VOID ReverseSymList(SYM **ppsymFirst)
{
    SYM *psymFirstNew;
    SYM *psym;
    SYM *psymNext;

    psymFirstNew = NULL;
    for (psym = *ppsymFirst; psym != NULL; psym = psymNext) {
        psymNext = psym->psymNext;
        psym->psymNext = psymFirstNew;
        psymFirstNew = psym;
    }
    *ppsymFirst = psymFirstNew;
}

VOID FreeSymList(SYM **ppsymFirst)
{
    SYM *psym;
    SYM *psymNext;

    for (psym = *ppsymFirst; psym != NULL; psym = psymNext) {
        psymNext = psym->psymNext;
        free(psym->sz);
        free(psym);
    }
    *ppsymFirst = NULL;
}

SYM *PsymLookup(SYM *psymFirst, char *sz)
{
    SYM *psym;

    for (psym = psymFirst; psym != NULL; psym = psym->psymNext) {
        if (strcmp(psym->sz, sz) == 0)
            return psym;
    }
    return NULL;
}


MEM *PmemAdd(SYM *psymStruct, char *sz, char *szType)
{
    MEM *pmem;
    SYM *psymType;
    MEM *pmemPrev;
    MEM *pmemT;

    if (gfPass2)
        return NULL;
    pmem = calloc(1, sizeof(MEM));
    pmem->sz = strdup(sz);
    psymType = PsymLookup(psymTypeFirst, szType);
    if (psymType == NULL)
        ErrorLine("Undefined type");
    pmem->psymType = psymType;
    pmemPrev = NULL;
    for (pmemT = psymStruct->pmemFirst; pmemT != NULL; pmemT = pmemT->pmemNext)
        pmemPrev = pmemT;
    if (pmemPrev == NULL)
        psymStruct->pmemFirst = pmem;
    else
        pmemPrev->pmemNext = pmem;
    return pmem;
}


// opt! could set psym->cb -- for now let's walk to the leafs
int CbFromSym(SYM *psym)
{
    MEM *pmem;
    int cb;

    cb = 0;
    if (psym->pmemFirst != NULL) {
        for (pmem = psym->pmemFirst; pmem != NULL; pmem = pmem->pmemNext)
            cb += CbFromSym(pmem->psymType);
        cb += (cb & 1);
    } else if (psym->psymType != NULL)
        cb = CbFromSym(psym->psymType);
    else
        cb = psym->u.cb;
    return cb;
}

void InitSym()
{
    PsymAddType("b", 1);
    PsymAddType("w", 2);
    PsymAddType("l", 4);
    // ? float ?
}


typedef struct _arg {
    char sz[128];
    SYM *psymType;
    //char szSize[128];
    //BOOL fStdSize;
    int cb;
    int ib;
    BOOL fEA;
    BOOL fConst;
} ARG;
#define iargMax 16


BOOL FParseArg(ARG *parg, BOOL fLocal)
{
    int cParen;
    BOOL fLocalSize;
    int ib;


    ClearSymContext();
    memset(parg, 0, sizeof(ARG));
    fLocalSize = fFalse;

    cParen = 0;
    parg->sz[0] = 0;
    switch (tok.lex.lt) {
    case ltId:
        if (tok.rw == rwSizeof) {
            int cb;

            FGetExpectLt(&tok, ltLParen, "(");
            FGetExpectLt(&tok, ltId, "sizeof struct");
            if (!FLookupSymCb(tok.lex.szId, &cb))
                ErrorLine("unknown type");
            sprintf(parg->sz, "#%d", cb);
            FGetExpectLt(&tok, ltRParen, ")");
            parg->fConst = fTrue;
            parg->cb =2;
            break;
        }
        if (tok.rw == rwNil && FLookupSym(tok.lex.szId, &parg->ib))
            break;

        strcpy(parg->sz, tok.lex.szId);
        if (cParen == 0 && tok.rw >= rwA0 && tok.rw <= rwA7)
            parg->cb = 4;
        //		psymContext = PsymLookupScope(tok.lex.szId, &parg->ib);
        break;
    case ltConst:
        // cb?
        break;
    case ltPound:
        parg->fConst = fTrue;
        parg->cb = 2;               // BUG!!!
        strcpy(parg->sz, "#");
        break;
    case ltAnd:
        parg->fEA = fTrue;
        parg->cb = 4;
        break;
    case ltLParen:
        strcpy(parg->sz, "(");
        cParen++;
        break;
    }

    while (FGetTok(&tok)) {
        switch (tok.lex.lt) {
        case ltPlus:
            ClearSymContext();
            break;
        case ltId:
            if (tok.rw == rwNil && FLookupSym(tok.lex.szId, &ib)) {
                parg->ib += ib;
                break;
            }
            if (cParen == 0 && tok.rw >= rwA0 && tok.rw <= rwA7)
                parg->cb = 4;
            // fall thru
        default:
            Id:
            if (fLocalSize)
                ; //				strcat(parg->szSize, tok.lex.szId);
            else
                strcat(parg->sz, tok.lex.szId);
            break;
        case ltRParen:
            cParen--;
            if (cParen < 0) {
                UngetTok();
                return fTrue;
            }
            goto Id;
            break;
        case ltLParen:
            cParen++;
            goto Id;
        case ltComma:
        case ltSemi:
            return fTrue;
            break;
        case ltPeriod:
            if (FGetTok(&tok)) {
                SYM *psym;

                if (tok.lex.lt == ltConst && !gfPass2)
                    PsymAddType(tok.lex.szId, tok.lex.val);

                psym = PsymLookup(psymTypeFirst, tok.lex.szId);
                parg->psymType = psym;
                if (psym != NULL)
                    parg->cb = CbFromSym(psym);
                if (tok.rw == rwNil && FLookupSym(tok.lex.szId, &ib)) {
                    parg->ib += ib;
                    break;
                }
            }
            break;
        }
    }
}

int ParseArgs(ARG *rgarg)
{
    ARG *parg;

    //	memset(rgarg, 0, sizeof(ARG)*iargMax);
    parg = rgarg;
    while (FGetTok(&tok)) {
        switch (tok.lex.lt) {
        case ltId:
        case ltConst:
        case ltAnd:
        case ltPound:
        case ltLParen:
            if (FParseArg(parg, fFalse))
                parg++;
            break;
        case ltRParen:
            return parg-rgarg;
        }
    }
    return 0;
}

int EmitArgs(ARG *rgarg, int iargMac)
{
    ARG *parg;
    int cb;

    cb = 0;
    while (iargMac--) {
        parg = &rgarg[iargMac];

        cb += parg->cb == 1 ? 2 : parg->cb;
        if (parg->fEA) {
            EmitSz("\tpea\t");
            if (parg->ib != 0)
                EmitW(parg->ib);

            EmitSz(parg->sz);
            //EmitSz("(a6)\n");
            EmitSz("\n");
            continue;
        }
        EmitSz("\tmove");
        switch (parg->cb) {
        default:
            ErrorLine("Invalid argument size");
            break;
        case 1:
            EmitSz(".b");
            break;
        case 2:
            EmitSz(".w");
            break;
        case 4:
            EmitSz(".l");
            break;
        }
        EmitSz("\t");
        if (parg->ib != 0)
            EmitW(parg->ib);
        EmitSz(parg->sz);
        EmitSz(",-(a7)\n");
    }
    return cb;
}

VOID ParseCall(RW rw)
{
    char szFunc[256];
    int cbArgs;
    int iargMac;
    ARG rgarg[iargMax];


    cbArgs = 0;
    if (!FGetExpectLt(&tok, ltId, "procedure name"))
        return;
    szFunc[0] = 0;
    if (rw == rwSysLibTrap)
        strcpy(szFunc, "sysLibTrap");
    else if (rw == rwSysTrap)
        strcpy(szFunc, "sysTrap");
    strcat(szFunc, tok.lex.szId);
    //	if (!FGetTok(&tok))
    //		return;
    //if (tok.lex.lt != ltNE)
    {
        //		UngetTok();
        if (!FGetExpectLt(&tok, ltLParen, "("))
            return;
        iargMac = ParseArgs(rgarg);
        cbArgs = EmitArgs(rgarg, iargMac);
    }
    switch (rw) {
    case rwCall:
        strcat(szFunc, "(pc)");
        EmitInst("jsr", szFunc, NULL);
        break;
    case rwSysTrap:
    case rwSysLibTrap:
        {
            EmitInst("trap", "#15", NULL);
            EmitInst("dc.w", szFunc, NULL);
            break;
        }
    }
    if (cbArgs > 0) {
        char sz[24];
        if (cbArgs <= 8) {
            sprintf(sz, "#%d", cbArgs);
            EmitInst("addq.l", sz, "a7");
        } else {
            sprintf(sz, "%d(a7)", cbArgs);
            EmitInst("lea", sz, "a7");
        }
    }
}


int ibArgPrev;

char gszProcId[cchIdMax];

void ParseProc()
{
    int cbArgs;
    int iargMac;
    int iarg;
    int ibArg;
    ARG rgarg[iargMax];

    ibArgPrev = 0;
    cbArgs = 0;
    if (!FGetExpectLt(&tok, ltId, "procedure name"))
        return;
    EmitInst("align", "2", NULL);
    EmitSz(tok.lex.szId);
    EmitSz(":\n");
    strcpy(gszProcId, tok.lex.szId);

    if (!FGetExpectLt(&tok, ltLParen, "("))
        return;
    iargMac = ParseArgs(rgarg);
    ibArg = 8;
    for (iarg = 0; iarg < iargMac; iarg++) {
        ARG *parg;
        char szT[16];

        parg = &rgarg[iarg];
        EmitSz(parg->sz);
        EmitSz("\tset\t");
        sprintf(szT, "%d\n", ibArg);
        EmitSz(szT);
        PsymAdd(&psymArgFirst, parg->sz, ibArg);
        ibArg += parg->cb;
    }
}


BOOL fInStruct;
SYM *psymStruct;

void ParseStruct()
{
    fInStruct = fTrue;
    if (!FGetExpectLt(&tok, ltId, "struct name"))
        return;
    if (!gfPass2)
        psymStruct = PsymAddType(tok.lex.szId, 0);
}



void ParseStructMember()
{
    char sz[256];


    if (tok.lex.lt != ltId)
        Error:
        ErrorLine("struct member or endstruct expected");
    strcpy(sz, tok.lex.szId);
    if (!FGetExpectLt(&tok, ltPeriod, "period"))
        return;
    if (!FGetTok(&tok))
        goto Error;
    // hack for constants!
    if (tok.lex.lt == ltConst && !gfPass2)
        PsymAddType(tok.lex.szId, tok.lex.val);
    PmemAdd(psymStruct, sz, tok.lex.szId);
}

void ParseEndStruct()
{
    if (!fInStruct) {
        ErrorLine("unexpected endstruct");
        return;
    }
    fInStruct = fFalse;
#ifdef EMIT_STRUCT_SIZES
    if (!gfPass2)
        printf("struct sizeof(%s)=%d\n", psymStruct->sz, CbFromSym(psymStruct));
#endif
    psymStruct = NULL;
}

SYM *psymContext;
VOID ClearSymContext()
{
    psymContext = NULL;
}


SYM *PsymLookupScope(char *sz)
{
    SYM *psym;

    psym = PsymLookup(psymLocalFirst, sz);
    if (psym != NULL)
        return psym;
    psym = PsymLookup(psymArgFirst, sz);
    if (psym != NULL)
        return psym;
    psym = PsymLookup(psymGlobalFirst, sz);
    if (psym != NULL)
        return psym;
    psym = PsymLookup(psymTypeFirst, sz);
    return psym;
}

int FLookupSym(char *sz, int *pw)
{
    MEM *pmem;
    int ib;

    if (psymContext == NULL) {
        SYM *psym;
        psym = PsymLookupScope(sz);
        if (psym == NULL || psym->fGlobal) {
            *pw = 0;
            return fFalse;
        } else {
            if (psym->fType) {
                *pw = 0;
                psymContext = psym;
            } else {
                *pw = psym->u.ib;
                psymContext = psym->psymType;
            }
            return fTrue;
        }
    }
    ib = 0;
    for (pmem = psymContext->pmemFirst; pmem != NULL; pmem = pmem->pmemNext) {
        if (strcmp(sz, pmem->sz) == 0) {
            *pw =  ib;
            psymContext = pmem->psymType;
            return fTrue;
        } else
            ib += CbFromSym(pmem->psymType);
    }
    psymContext = NULL;
    return fFalse;
}

int FLookupSymCb(char *sz, int *pcb)
{
    SYM *psym;

    *pcb = 0;
    psym = PsymLookup(psymTypeFirst, sz);
    if (psym == NULL)
        return fFalse;
    *pcb = CbFromSym(psym);
    return fTrue;
}




void ParseLocal()
{
    ARG arg;
    SYM *psym;

    if (!FGetTok(&tok))
        return;
    FParseArg(&arg, fTrue);
    ibArgPrev -= arg.cb;
    psym = PsymAdd(&psymLocalFirst, arg.sz, arg.cb);
    if (psym != NULL)
        psym->psymType = arg.psymType;
}

int ibGlobal;
void ParseGlobal()
{
    ARG arg;
    SYM *psym;

    if (!FGetTok(&tok))
        return;
    FParseArg(&arg, fTrue);
    EmitSz(arg.sz);
    EmitSz("\tds.b\t");
    EmitW(arg.cb);
    EmitSz("\n");
    if (!gfPass2) {
        psym = PsymAdd(&psymGlobalFirst, arg.sz, ibGlobal);
        psym->fGlobal = fTrue;
        ibGlobal += arg.cb;
        if (psym != NULL)
            psym->psymType = arg.psymType;
    }
}



void ParseBeginProc()
{
    char szT[256];
    SYM *psym;
    int ib;

    sprintf(szT, "#%d", ibArgPrev);
    EmitInst("link", "a6", szT);
    ib = 0;
    ReverseSymList(&psymLocalFirst);
    for (psym = psymLocalFirst; psym != NULL; psym = psym->psymNext) {
        ib -=CbFromSym(psym);
        psym->u.ib = ib;
    }
}

void ParseEndProc()
{
    extern int gfEmitProcSymbols;

    EmitInst("unlk", "a6", NULL);
    EmitInst("rts", NULL, NULL);

    if (gfEmitProcSymbols) {
        char szT[cchIdMax + 8];
        sprintf(szT, "$%x,'%s',0", strlen(gszProcId) | 0x80, gszProcId);
        EmitInst("dc.b", szT, NULL);
        EmitInst("align", "2", NULL);
    }

    FreeSymList(&psymLocalFirst);
    FreeSymList(&psymArgFirst);
}


MDL MdlGetLine(char *sz, int cchMax, FILE *pfile)
{
    if (pelFirst != NULL) {
        EL *pel;

        strcpy(sz, pelFirst->sz);
        pel = pelFirst;
        pelFirst = pelFirst->pelNext;
        free(pel);
        return mdlPseudoLine;
    }
    fTokUngotten = fFalse;
    if (!fgets(sz, cchMax, pfile))
        return mdlEOF;

    if (!FInitLexer(sz, fTrue))
        return mdlEOF;
    if (!FGetTok(&tok))
        return mdlNormalLine;
    switch (tok.rw) {
    default:
        if (fInStruct)
            ParseStructMember();
        else
            return mdlNormalLine;
        break;
    case rwCall:
        ParseCall(tok.rw);
        break;
    case rwProc:
        ParseProc();
        break;
    case rwSysTrap:
    case rwSysLibTrap:
        ParseCall(tok.rw);
        break;
    case rwLocal:
        ParseLocal();
        break;
    case rwGlobal:
        ParseGlobal();
        break;
    case rwBeginProc:
        ParseBeginProc();
        break;
    case rwEndProc:
        ParseEndProc();
        break;
    case rwStruct:
        ParseStruct();
        break;
    case rwEndStruct:
        ParseEndStruct();
        break;
    }
    return mdlIgnoreLine;
}

