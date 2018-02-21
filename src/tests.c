#include "../include/treeStructure.h"
#include "../include/buildTree.h"
#include "../include/writeTree.h"
#include "../include/destroyTree.h"
#include "../include/growTree.h"
#include "../include/tests.h"


void task1() {
    Node *head;
    head = makeNode(0.0, 0.0, 0);

    //Tree structure
    makeChildren(head);
    makeChildren(head->child[0]);
    makeChildren(head->child[1]);
    makeChildren(head->child[3]);
    makeChildren(head->child[1]->child[1]);
    makeChildren(head->child[3]->child[2]);
    makeChildren(head->child[3]->child[3]);

    destroyTree(head);
    //writeTree(head);
}

void task2() {
    Node *head;
    head = makeNode(0.0, 0.0, 0);

    //Tree structure
    makeChildren(head);
    makeChildren(head->child[0]);
    makeChildren(head->child[1]);
    makeChildren(head->child[2]);
    makeChildren(head->child[3]);

    growTree(head);
    writeTree(head);
    destroyTree(head);
}

void task3() {

}

void task4() {

}
