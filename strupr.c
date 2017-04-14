#include <ctype.h>

#include "strupr.h"

void strupr(char *s) {
	while (*s != '\0') {
		*s = toupper(*s);
		s++;
	}
}
