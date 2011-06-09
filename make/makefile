OBJS = main.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LIBS = -lboost_thread-mt
LDFLAGS = -Wall $(DEBUG) $(LIBS)

main : $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o main

clean:
	rm -f *.o main

.PHONY: clean 
