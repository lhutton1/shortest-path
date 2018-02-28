#ifndef _VALUETREE_
#define _VALUETREE_

double dataFunction(double x, double y, int choice);
bool indicator(Node *node, double tolerance, int choice);
void visitLeafNodes(Node *node, double tolerance, int choice, int *falseResults);
void growTreeUsingData(Node *head, double tolerence, int choice);

#endif
