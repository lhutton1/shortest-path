#include <stdlib.h>
#include "../include/treeStructure.h"
#include "../include/buildTree.h"
#include "../include/growTree.h"

void growTree(Node *head) {
    growNode(head);
}

void growNode(Node *node) {
    if (node->child[0] == NULL)
        makeChildren(node);
    else {
        for (int i = 0; i < 4; ++i)
            growNode(node);
    }
}