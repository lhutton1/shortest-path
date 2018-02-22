IDIR=include
CC=gcc
CFLAGS=-I$(IDIR)

ODIR=src
LDIR=lib

LIBS=-lm

_DEPS=buildTree.h destroyTree.h growTree.h treeStructure.h writeTree.h tests.h valueTree.c
DEPS=$(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ=main.o buildTree.o destroyTree.o growTree.o writeTree.o tests.o valueTree.o
OBJ=$(patsubst %,$(ODIR)/%,$(_OBJ))

_OUT=out

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c $< -o $@ $(CFLAGS)

main: $(OBJ)
	gcc -o $(_OUT)/$@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~
