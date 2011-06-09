##----------------------------------------------------------------------------
# Created with genmake.pl v1.1 on Mon Dec 29 16:21:07 2008
# genmake.pl home: http://muquit.com/muquit/software/
# Copryright: GNU GPL (http://www.gnu.org/copyleft/gpl.html)
##----------------------------------------------------------------------------
rm=/bin/rm -f
CC= cc
LINK= -=LINK=-
DEFS=  
AR= ar cq
RANLIB= /usr/bin/ranlib
LIBNAME= libmyapp.a

INCLUDES=  -I. -I..

DEFINES= $(INCLUDES) $(DEFS) -DSYS_UNIX=1
CFLAGS= -g $(DEFINES)

SRCS = main.cpp 

OBJS = main.o 

.c.o:
	$(rm) -f $@
	$(CC) $(CFLAGS) -c $*.c

all: $(LIBNAME)

$(LIBNAME) : $(OBJS)
	$(rm) $@
	$(AR) $@ $(OBJS)
	$(RANLIB) $@

clean:
	$(rm) $(OBJS) $(LIBNAME) core *~
