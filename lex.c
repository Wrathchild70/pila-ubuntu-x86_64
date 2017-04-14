/*-----------------------------------------------------------------------------
|	lex.c
|	
|	Mocha lexer
-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#define NOPILOTINC
//#include "pilrc.h"
#include "std.h"
#include "util.h"
#include "lex.h"


int wBaseCur = 10;

char *pchLexBuf;
char *pchLexPrev;
char *pchLex;

char *_pchParseError;
BOOL _fReportErrors;

BOOL FInitLexer(char *pch, BOOL fMarkErrors)
{
    pchLexBuf = pch;
    pchLex = pch;
    pchLexPrev = pch;
    _pchParseError = NULL;
    _fReportErrors = fMarkErrors;
    return fTrue;
}

char *PchLexer()
{
    return pchLex;
}

char *PchLexerPrev()
{
    return pchLexPrev;
}

VOID ParseError(char *sz1, char *sz2)
{
    _pchParseError = PchLexerPrev();
    ErrorLine(sz1);
}

char *PchParseError()
{
    return _pchParseError;
}





BOOL FSkipWhite()
{
    if (pchLex == NULL)
        return fFalse;
    while (*pchLex == ' ' || *pchLex == '\t' || *pchLex == '\n' || *pchLex == '\r')
        pchLex++;
    return (*pchLex != '\000');
}

BOOL FParseHex(LEX *plex, int ch)
{
    LEX lex;
    char *pchStore;

    pchStore = lex.szId;

    if (ch == '$') {
        *pchStore++=ch;
        ch = *pchLex++;
        }
    ch = tolower(ch);
    if (ch == '0' && *(pchLex) == 'x' || *(pchLex) == 'X') {
        *pchStore++ = ch;
        pchLex++;
        ch = *pchLex++;
    }
    if ((ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'f')) {
        //*pchStore++ = ch;
        lex.lt = ltConst;
        lex.val = 0;
        while ((ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'f')) {
           *pchStore++ = ch;
           lex.val *= 16;

            if ((ch >= '0' && ch <= '9'))
                lex.val += ch-'0';
            else
                lex.val += ch-'a'+10;
            ch = *pchLex++;
            ch = tolower(ch);
        }
        *pchStore = 0;

        *plex = lex;
        return fTrue;
    }
    return fFalse;
}

BOOL FParseConst(LEX *plex, int ch)
{
    LEX lex;
    char *pchSav;
    extern int wBaseCur;
    char *pchStore;


    pchStore = lex.szId;
    *pchStore = ch;
    pchSav = pchLex;
    if (ch == '$') {
        return FParseHex(plex, ch);
    }
#ifdef LATER
    if (wBaseCur == 2)
        return FParseBin(plex, ch);
#endif
    Assert(wBaseCur == 10);
    if ((ch >= '0' && ch <= '9')) { //  || ch == '.')
        lex.lt = ltConst;
        lex.val = 0;
        if (ch == '0' && *(pchLex) == 'x' || *(pchLex) == 'X') {
            *pchStore++ = *pchLex++;
            *pchStore++ = ch = *pchLex++;
            return FParseHex(plex, ch);
        }
        while (ch >= '0' && ch <= '9') {
            lex.val *= 10;
            lex.val += ch-'0';
            *pchStore++ = ch;
            ch = *pchLex++;
        }
        *pchStore = 0;
        *plex = lex;
        return fTrue;
    }
    return fFalse;
}

BOOL FParseId(LEX *plex, int ch)
{
    LEX lex;

    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || ch == '_') {
        // Identifier
        int cch;

        lex.lt = ltId;
        cch = 0;
        do {
            //            if (ch != '"')
            {
                lex.szId[cch] = ch;
                cch++;
            }
            ch = *pchLex++;
            if (cch == cchIdMax-1) {
                ParseError("Identifier too long", NULL);
                break;
            }
        }
        while ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9') || ch == '_');
        lex.szId[cch] = '\000';
        *plex = lex;
        return fTrue;
    }
    return fFalse;
}

#define SLT(ch, ltArg) case ch: lex.lt = ltArg; break;

BOOL FGetLexUntilRgch(LEX *plex, char *szTerm)
{
    char *pchStore;

    plex->lt = ltStr;   // ?
    pchStore = plex->szId;
    while (*pchLex != 0 && strchr(szTerm, *pchLex) == NULL) {
        pchLexPrev = pchLex;
        *pchStore++ = *pchLex++;
    }
    *pchStore = 0;
    return pchStore != plex->szId;
}

BOOL FGetLex(LEX *plex)
{
    int ch;
    char szT[2];
    LEX lex;
    char *pchSav;
    char *pchStore;


    lex.lt = plex->lt = ltNil;
    pchLexPrev = pchLex;
    if (!FSkipWhite())
        return fFalse;
    pchSav = pchLex;
    pchStore = lex.szId;
    *pchStore++ = ch = *pchLex++;

    switch (ch) {
    // BUG! could use a lookup table...
    //TODO logical operators
    SLT('+', ltPlus)
    SLT('-', ltMinus)
    SLT('*',    ltMult)
    SLT('/', ltDiv)
    SLT('%', ltMod)
    SLT('(', ltLParen)
    SLT(')', ltRParen)
    SLT('[', ltLBracket)
    SLT(']', ltRBracket)
    SLT(',', ltComma)
    SLT('?', ltQuestion)
    SLT(':', ltColon)
    SLT('^', ltCaret)
    SLT('\\', ltBSlash)
    SLT(';', ltSemi)
    SLT('.', ltPeriod)
    SLT('#', ltPound)
    SLT('&', ltAnd)
    case '<':
        if (*pchLex == '=') {
            *pchStore++ = *pchLex++;
            lex.lt = ltLTE;
        } else if (*pchLex == '>') {
            *pchStore++ = *pchLex++;
            lex.lt = ltNE;
        } else
            lex.lt = ltLT;
        break;
    case '>':
        if (*pchLex++ == '=') {
            *pchStore = *pchLex++;
            lex.lt = ltGTE;
        } else
            lex.lt = ltGT;
        break;
    case '=':
        if (*pchLex == '=') {
            *pchStore++ = *pchLex++;
            lex.lt = ltEQ;
        } else
            lex.lt = ltAssign;
        break;
    case '"':
        lex.lt = ltStr;
        pchStore = lex.szId;
        while (*pchLex != '"') {
            if (*pchLex == '\\') {
                int ch;

                pchLex++;
                ch = *pchLex++;
                if (ch == 'n')
                    ch = 0x0a;
                else if (ch == 't')
                    ch = '\t';
                *pchStore++ = ch;
            } else
                *pchStore++ = *pchLex++;
            if (pchStore-lex.szId == cchIdMax-1) {
                ParseError("String too long", NULL);
                break;
            }
            if (*pchLex == 0) {
                ParseError("Unterminated string", NULL);
                break;
            }
        }
        pchLex++;
        *pchStore = 0;
        break;
    default:
        if (FParseConst(&lex, ch) || FParseId(&lex, ch)) {
            // do nuthin...code is easier to read this way
        } else {
            szT[0] = ch;
            szT[1] = '\000';
            ParseError("Unknown character: ", szT);
        }
        pchLex--;
        break;
    }
    if (lex.lt != ltConst && lex.lt != ltId)
        *pchStore = 0;
    *plex = lex;
    return lex.lt != ltNil;
}

#define SPLT(lt, sz) case lt: printf(sz); break;

VOID PrintLex(LEX *plex)
{
#ifdef FOO
    switch (plex->lt) {
    case ltConst:
        printf("%d ", plex->val);
        break;
    case ltId:
        printf("%s ", plex->szId);
        break;
        SPLT(ltPlus, "+");
        SPLT(ltMinus, "-");
        SPLT(ltMult, "*");
        SPLT(ltDiv, "/");
        SPLT(ltMod, "%");
        SPLT(ltLParen, "(");
        SPLT(ltRParen, ")");
        SPLT(ltLBracket, "[");
        SPLT(ltRBracket, "]");
        SPLT(ltComma, ",");
        SPLT(ltLT, "<");
        SPLT(ltGT, ">");
        SPLT(ltLTE, "<=");
        SPLT(ltGTE, ">=");
        SPLT(ltNE, "<>");
        SPLT(ltEQ, "==");
        SPLT(ltAssign, "=");
        SPLT(ltQuestion, "?");
        SPLT(ltColon, ":");
        SPLT(ltCaret, "^");
    }
#endif
}

