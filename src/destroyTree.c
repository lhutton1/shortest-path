#include "../include/destroyTree.h"


// Destroy whole tree starting from head
void destroyTree(Node *head) {
    printf("Destroying tree\n");
    destroyNode(head);
}


// Destroy node and all sub nodes recursively
void destroyNode(Node *node) {
    for (int i = 0; i < 4; ++i) {
        if (node->child[i] != NULL)
            destroyNode(node->child[i]);
    }

    free(node);
}

