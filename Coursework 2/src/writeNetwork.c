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
  char *color;

  for (int i = 0; i < network->noNodes - 1; i++) {
    currentNode = &network->adjacencyListArray[i];
    currentEdge = network->adjacencyListArray[i].head;

    if(currentEdge == NULL) continue;

    adjacentNode = getNode(network, currentEdge->node);

    while (currentEdge != NULL) {
      adjacentNode = getNode(network, currentEdge->node);

      if (currentNode->path)
        color = "0xFF0000"; // red color for path lines
      else
        color = "0x0000FF"; // blue color for non path lines

      fprintf(fp, "%g %g %s\n", currentNode->x, currentNode->y, color);
      fprintf(fp, "%g %g %s\n", adjacentNode->x, adjacentNode->y, color);
      fprintf(fp, "\n");

      currentEdge = currentEdge->next;
    }
  }
}
