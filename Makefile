# Makefile for 'hashtable' module
#
# written by Daniel Lynch, April 2020


PROG = hashtabletest
OBJS = jhash.o ../set/set.o hashtabletest.o hashtable.o ../common/readlinep.o ../common/memory.o 
LIBS =

# uncomment the following to turn on verbose memory logging
# TESTING=-DMEMTEST

CFLAGS = -Wall -pedantic -std=c11 -ggdb $(TESTING) -I../common -I../set
CC = gcc
MAKE = make

$(PROG): $(OBJS)
	$(CC) $(CFLAGS) $^ $(LIBS) -o $@

hashtabletest.o: hashtable.h ../common/readlinep.h
hashtable.o: ../set/set.h jhash.h hashtable.h
readline.o: ../common/readlinep.h
jhash.o: jhash.h
../set/set.o: ../set/set.h

.PHONY: clean test





test: $(PROG) testing.out
	./$(PROG) > testing.out

clean:
	rm -f *~ *.o *.dSYM
	rm -f $(PROG)
	rm -f stocks
