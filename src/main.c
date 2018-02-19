#include "treeStructure.h"
#include "buildTree.h"
#include "writeTree.h"


int main(int argc, char **argv) {

    Node *head;

    // make the head node
    head = makeNode(0.0, 0.0, 0);

    // make a tree
    makeChildren(head);
    makeChildren(head->child[1]);
    makeChildren(head->child[2]);
    makeChildren(head->child[2]->child[3]);
    makeChildren(head->child[1]->child[2]);

    // print the tree for Gnuplot
    writeTree(head);

    // destroy tree and clear memory
    destroyTree(head);

    return 0;
}
