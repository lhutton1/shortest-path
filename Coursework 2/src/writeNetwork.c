#include <stdio.h>
#include <stdbool.h>

#include "networkStructure.h"
#include "networkUtils.h"
#include "writeNetwork.h"

// Write out the tree to file 'quad.out'
void writeNetwork(NetworkP network) {
  FILE *fp = fopen("out/network.out", "w");
  writeEdge(fp, network);
  fclose(fp);
}

void writeEdge(FILE *fp, NetworkP network) {
  AdjListP currentNode;
  AdjListP adjacentNode;
  AdjListNodeP currentEdge;
  AdjListNodeP adjacentEdge;
  bool color;

  for (int i = 0; i < network->noNodes - 1; i++) {
    currentNode = &network->adjacencyListArray[i];
    currentEdge = network->adjacencyListArray[i].head;

    if(currentEdge == NULL) continue;

    adjacentNode = getNode(network, currentEdge->node);

    while (currentEdge != NULL) {
      adjacentNode = getNode(network, currentEdge->node);



      if (currentNode->parent != NULL) {
        printf("%p\n", currentNode->parent);
        color = true;
      }
      else
        color = false;

      fprintf(fp, "%g %g %d\n", currentNode->x, currentNode->y, color);
      fprintf(fp, "%g %g %d\n", adjacentNode->x, adjacentNode->y, color);
      fprintf(fp, "\n");

      currentEdge = currentEdge->next;
    }
  }
}
