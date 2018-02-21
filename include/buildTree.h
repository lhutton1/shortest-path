#ifndef _BUILDTREE_
#define _BUILDTREE_

Node *makeNode(double x, double y, int level);
void makeChildren(Node *parent);
void destroyTree(Node *head);
void destroyNode(Node *node);

#endif