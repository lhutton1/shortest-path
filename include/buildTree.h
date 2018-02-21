#ifndef _BUILDTREE_
#define _BUILDTREE_

#include <math.h>
#include <stdlib.h>
#include "treeStructure.h"

Node *makeNode(double x, double y, int level);
void makeChildren(Node *parent);
void destroyTree(Node *head);
void destroyNode(Node *node);

#endif