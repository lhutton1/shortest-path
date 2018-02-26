#include "../include/treeStructure.h"
#include "../include/buildTree.h"
#include "../include/writeTree.h"
#include "../include/destroyTree.h"
#include "../include/growTree.h"
#include "../include/valueTree.h"
#include "../include/tests.h"

const int MAX_LEVEL = 100;

void task1() {
    Node *head;
    head = makeNode(0.0, 0.0, 0);

    //Tree structure
    makeChildren(head);
    makeChildren(head->child[0]);
    makeChildren(head->child[1]);
    makeChildren(head->child[3]);

    destroyTree(head);
    //writeTree(head);
}

void task2() {
    Node *head;
    head = makeNode(0.0, 0.0, 0);

    //Tree structure
    makeChildren(head);
    makeChildren(head->child[0]);
    makeChildren(head->child[2]);
    makeChildren(head->child[0]->child[1]);
    makeChildren(head->child[2]->child[0]);
    makeChildren(head->child[2]->child[3]);

    growTree(head);
    writeTree(head);
    destroyTree(head);
}

void task3() {
    Node *head;
    head = makeNode(0.0, 0.0, 0);

    //Tree structure
    makeChildren(head);
    growTree(head);
    growTree(head);
    growTree(head);

    //Test
    growTree(head);

    writeTree(head);
    destroyTree(head);
}

void task4() {
    Node *head;
    head = makeNode(0.0, 0.0, 0);

    makeChildren(head);
    growTree(head);

    growTreeUsingData(head, 0.2, 1);

    writeTree(head);
    destroyTree(head);
}