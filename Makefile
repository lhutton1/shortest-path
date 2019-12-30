IDIR=include
CC=gcc
CFLAGS=-I$(IDIR)

ODIR=src
LDIR=lib

LIBS=-lm

_DEPS=networkStructure.h readFile.h buildNetwork.h nodeHash.h networkUtils.h binaryHeap.h priorityQueue.h dijkstrasAlgorithm.h writeNetwork.h constants.h handleError.h
DEPS=$(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ=main.o readFile.o buildNetwork.o networkUtils.o binaryHeap.o priorityQueue.o dijkstrasAlgorithm.o writeNetwork.o handleError.o
OBJ=$(patsubst %,$(ODIR)/%,$(_OBJ))

_OUT=out

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c $< -o $@ $(CFLAGS)

main: $(OBJ)
	gcc -o $(_OUT)/$@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~
