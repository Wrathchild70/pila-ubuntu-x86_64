/***********************************************************************
 *
 *		MAIN.C
 *		Main Module for 68000 Assembler
 *
 *    Function: main()
 *		Parses the command line, opens the input file and
 *		output files, and calls processFile() to perform the
 *		assembly, then closes all files.
 *
 *	 Usage: main(argc, argv);
 *		int argc;
 *		char *argv[];
 *
 *      Author: Paul McKee
 *		ECE492    North Carolina State University
 *
 *        Date:	12/13/86
 *
 ************************************************************************/

#include "pila.h"
#include "asm.h"
#include "prc.h"

extern FILE *gpfilList; /* List file */
extern char line[256];  /* Source line */
extern int errorCount, warningCount;    /* Number of errors and warnings */

extern char cexFlag;    /* True is Constants are to be EXpanded */

int gfDebugOutput = FALSE;
int gfResourcesOnly = FALSE;
int gfEmitProcSymbols = FALSE;
int gfListOn = FALSE;
char gszAppName[_MAX_PATH];
FourCC gfcPrcType = 'appl';

int main(int argc, char *argv[])
{
    extern int SetArgFlags(char **apszArgs, int cpszArgs);
    extern long gcbDataCompressed;
    char pszFile[_MAX_PATH], outName[_MAX_PATH], *p;
    int i;
    long cbRes, cbPrc;
    char szErrors[80];

    puts("Pila 1.0 Beta 3\n");

    i = SetArgFlags(argv, argc);
    if (i == 0)
        help();

    gszAppName[0] = 0;

    /* Check whether a name was specified */

    if (i >= argc) {
        fputs("No input file specified\n\n", stdout);
        help();
    }

    if (!strcmp("?", argv[i]))
        help();

    strcpy(pszFile, argv[i]);

    /* Process output file names in their own buffer */

    strcpy(outName, pszFile);

    /* Change extension to .LIS */

    p = strchr(outName, '.');
    if (!p)
        p = outName + strlen(outName);

    if (gfListing) {
        strcpy(p, ".LIS");
        initList(outName);
    }

    strcpy(p, ".prc");

    /* Assemble the file */
    InitSym();
    processFile(pszFile);

    /* Close files and print error and warning counts */

    //PopSourceFile();

    // Get the resource total before WritePrc adds in the code and data
    // resources.

    cbRes = gcbResTotal;

    // If no errors, write the PRC file.

    cbPrc = 0;
    if (errorCount == 0) {
        cbPrc = WritePrc(outName, gszAppName, gpbCode, gulCodeLoc, gpbData, gulDataLoc);
        fprintf(stdout, "Code: %d bytes\nData: %d bytes (%d compressed)\n"
                "Res:  %d bytes\nPRC:  %d bytes\n",
                gulCodeLoc, gulDataLoc, gcbDataCompressed, cbRes, cbPrc);
    }

    sprintf(szErrors, "%d error%s, %d warning%s\n",
            errorCount, (errorCount != 1) ? "s" : "",
            warningCount, (warningCount != 1) ? "s" : "");

    fprintf(stdout, szErrors);

    if (gfListing) {
        putc('\n', gpfilList);
        fprintf(gpfilList, szErrors);
        fclose(gpfilList);
    }

    return errorCount;
}


// Uppercase everything that isn't inside of single or double quotes

int strcap(char *d, char *s)
{
    char capFlag;

    capFlag = TRUE;
    while (*s) {
        if (capFlag)
#ifdef CASE_SENSITIVE
            *d = *s;
#else
            *d = toupper(*s);
#endif
        else
            *d = *s;
        if (*s == '\'' || *s == '\"')
            capFlag = (char) !capFlag;
        d++;
        s++;
    }
    *d = '\0';

    return NORMAL;
}


char *skipSpace(char *p)
{
    while (isspace(*p))
        p++;
    return p;
}

int SetArgFlags(char **apszArgs, int cpszArgs)
{
    int i;
    for (i = 1; i < cpszArgs && apszArgs[i][0] == '-'; i++) {
        char ch;
        char *pszArg = apszArgs[i] + 1, *pch;
        while ((ch = *pszArg++) != 0) {
            switch (ch) {
            case 'd':
                gfDebugOutput = TRUE;
                break;

            case 'c':
                cexFlag = TRUE;
                break;

            case 'l':
                gfListing = TRUE;
                gfListOn = TRUE;
                break;

            case 'r':
                gfResourcesOnly = TRUE;
                break;

            case 'h':
            case '?':
                help();
                break;

            case 's':
                gfEmitProcSymbols = TRUE;
                break;

            case 't':
                if (*pszArg != 0) {
                    fprintf(stdout, "-t must be followed by a space and a "
                            "four character type.\n");
                    return 0;
                }

                if (i + 1 >= cpszArgs) {
                    fprintf(stdout, "-t requires four character type.\n");
                    return 0;
                }

                pch = apszArgs[++i];
                if (strlen(pch) != 4) {
                    fprintf(stdout, "-t requires four character type.\n");
                    return 0;
                }

                gfcPrcType = ReverseLong(*(ulong *)pch);
                break;

            default:
                fprintf(stdout, "Unknown option -%c\n", ch);
                return 0;
            }
        }
    }

    return i;
}


/**********************************************************************
 *
 *	Function help() prints out a usage explanation if a bad
 *	option is specified or no filename is given.
 *
 *********************************************************************/

int help()
{
    puts("Usage: pila [-cldrs] [-t TYPE] infile.ext\n");
    puts("Options: -c  Show full constant expansions for DC directives");
    puts("         -l  Produce listing file (infile.lis)");
    puts("         -d  Debugging output");
    puts("         -r  Resources only, don't generate code or data");
    puts("         -s  Include debugging symbols in output");
    puts("    -t TYPE  Specify the PRC type, e.g., appl");
    exit(0);
    return NORMAL;
}
