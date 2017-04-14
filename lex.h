
#ifndef __lex__
#define __lex__


typedef int LT;

    #define ltNil     -1
// must be same as nt's
    #define ltConst    0
    #define ltId       1
    #define ltPlus     2
    #define ltMinus    3
    #define ltMult     4
    #define ltDiv      5
    #define ltMod      6

// WARNING: PexnExpr assumes order
    #define ltLT       7
    #define ltGT       8
    #define ltEQ       9
    #define ltLTE      10
    #define ltGTE      11
    #define ltNE       12
    #define ltCaret	 13
    #define ltAssign   14
    #define ltBSlash  15
// END WARNING
    #define ltSemi 16
    #define ltPeriod 17
    #define ltPound 18
    #define ltAnd 19

    #define ltLParen   42
    #define ltRParen   43
    #define ltLBracket 44
    #define ltRBracket 45
    #define ltComma    46
    #define ltQuestion 47
    #define ltColon    48
    #define ltStr      49


typedef int VAL;

    #define cchIdMax 1024
// LEXeme
typedef struct _lex {
    LT lt;
    char szId[cchIdMax];
    VAL val;
} LEX;



// Lex function prototypes
BOOL FInitLexer(char *pch, BOOL fReportErrors);
char *PchLexer();
BOOL FSkipWhite();

char *PchLexerPrev();
BOOL FGetLex(LEX *plex);
VOID PrintLex(LEX *plex);
char *PchParseError();
VOID ParseError(char *, char *);

BOOL FGetLexUntilRgch(LEX *plex, char *szTerm);



#endif // __lex__

