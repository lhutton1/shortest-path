#include "../include/growTree.h"

// Grow tree starting from head
void growTree(Node *head) {
    printf("Growing tree\n");
    growNode(head);
}

// Grow tree from starting node
void growNode(Node *node) {
    if (node->child[0] == NULL)
        makeChildren(node);
    else {
        for (int i = 0; i < 4; ++i)
            growNode(node->child[i]);
    }
}