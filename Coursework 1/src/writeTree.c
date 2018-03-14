#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../include/treeStructure.h"
#include "../include/writeTree.h"


// Write out the tree to file 'quad.out'
void writeTree(Node *head) {
    FILE *fp = fopen("out/quad.out", "w");
    writeNode(fp, head);
    fclose(fp);
}


// Recursively visit the leaf nodes
void writeNode(FILE *fp, Node *node) {
    int i;

    if (node->child[0] == NULL)
        printOut(fp, node);
    else {
        for (i = 0; i < 4; ++i)
            writeNode(fp, node->child[i]);
    }
}


// Write out the (x,y) corners of the node
void printOut(FILE *fp, Node *node) {
    double x = node->xy[0];
    double y = node->xy[1];
    int level = node->level;
    double h = pow(2.0, -level);

    fprintf(fp, " %g %g\n", x, y);
    fprintf(fp, " %g %g\n", x + h, y);
    fprintf(fp, " %g %g\n", x + h, y + h);
    fprintf(fp, " %g %g\n", x, y + h);
    fprintf(fp, " %g %g\n\n", x, y);
}