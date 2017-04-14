#
# Pila makefile
#

CC       = gcc
CFLAGS   = -g -Dunix
LDFLAGS  =

SRCS     = assemble.c build.c codegen.c directiv.c error.c eval.c globals.c \
           instlook.c insttabl.c lex.c listing.c main.c movem.c object.c \
           opparse.c pp.c prc.c strupr.c symbol.c
OBJS     = $(SRCS:.c=.o)

pila: $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $+ $(LOADLIBES)

%.o: %.c
	$(CC) -c $(CPPFLAGS) $(CFLAGS) -o $@ $+

clean:
	rm -f $(OBJS) pila core
