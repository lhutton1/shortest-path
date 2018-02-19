# code details

EXE_DIR = /src/
EXE = $(EXE_DIR)main

SRC= /src/main.c

DEPS = buildTree.h destroyTree.h growTree.h treeStructure.h writeTree.h


# generic build details

CC=      gcc
CFLAGS=  -g -I../include
LIBS=    -lm
OBJ=     main.o buildTree.o destroyTree.o growTree.o writeTree.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

# build executable

main: $(OBJ)
	$(CC) $(LIBS) -o main $^ $(CFLAGS)



# clean up compilation

.PHONY: clean

clean:
	rm -f $(OBJ) $(EXE)
