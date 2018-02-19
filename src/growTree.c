#include <stdlib.h>
#include "../inc/treeStructure.h"
#include "../inc/buildTree.h"
#include "../inc/growTree.h"

void growTree(Node *head) {
    growNode(head);
}

void growNode(Node *node) {
    if (node->child[0] == NULL)
        makeChildren(node);
    else {
        for (i = 0; i < 4; ++i)
            growNode(node);
    }
}