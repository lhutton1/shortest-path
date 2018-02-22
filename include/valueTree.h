#ifndef _VALUETREE_
#define _VALUETREE_

#include <stdbool.h>

double dataFunction( double x, double y, int choice );
bool indicator( Node *node, double tolerance, int choice );
int noFalseResults;
void visitLeafNodes(Node *node, double tolerance, int choice);
void growTreeUsingData(Node *head, double tolerence, int choice);

#endif
