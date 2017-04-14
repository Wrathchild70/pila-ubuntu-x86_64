#ifndef __PILA_H__
#define __PILA_H__

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <limits.h>
#include <string.h>
#ifdef 0 /* DPN */
#include <Windows.h>
#endif

#ifndef _MAX_PATH
#define _MAX_PATH PATH_MAX
#endif

#ifdef unix
#define stricmp strcasecmp
#define strcmpi strcasecmp
#endif

#endif /* __PILA_H__ */
