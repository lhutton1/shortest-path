#ifndef _WRITETREE_
#define _WRITETREE_

#include <stdio.h>

void writeTree(Node *head);
void writeNode(FILE *fp, Node *node);
void printOut(FILE *fp, Node *node);

#endif