#include <stdio.h>
#include <stdbool.h>

#include "networkStructure.h"
#include "networkUtils.h"
#include "writeNetwork.h"
#include "constants.h"


// Write out the tree to file 'quad.out'. This function opens the file
// and writes each edge to the file for gnuplot to read and consruct the
// network.
void writeNetwork(NetworkP network) {
  FILE *fp = fopen("out/network.out", "w");
  AdjListP currentNode;
  AdjListP adjacentNode;
  AdjListNodeP currentEdge;
  AdjListNodeP adjacentEdge;

  for (int i = 0; i < network->noNodes - 1; i++) {
    currentNode = &network->adjacencyListArray[i];
    currentEdge = network->adjacencyListArray[i].head;

    if(currentEdge == NULL) continue;

    adjacentNode = getNode(network, currentEdge->node);

    while (currentEdge != NULL) {
      adjacentNode = getNode(network, currentEdge->node);
      writeEdge(fp, network, currentNode, adjacentNode);
      currentEdge = currentEdge->next;
    }
  }
  fclose(fp);
}


// Write a single edge to the gnuplot file
void writeEdge(FILE *fp, NetworkP network, AdjListP currentNode, AdjListP adjacentNode) {
  if (currentNode->path) {
    fprintf(fp, "%g %g %s\n", currentNode->x, currentNode->y, PATH_EDGE_COLOUR);
    fprintf(fp, "%g %g %s\n", adjacentNode->x, adjacentNode->y, PATH_EDGE_COLOUR);
  } else {
    fprintf(fp, "%g %g %s\n", currentNode->x, currentNode->y, EDGE_COLOUR);
    fprintf(fp, "%g %g %s\n", adjacentNode->x, adjacentNode->y, EDGE_COLOUR);
  }

  fprintf(fp, "\n");
}
