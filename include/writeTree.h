#ifndef _WRITETREE_
#define _WRITETREE_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "treeStructure.h"

void writeTree(Node *head);
void writeNode(FILE *fp, Node *node);
void printOut(FILE *fp, Node *node);

#endif