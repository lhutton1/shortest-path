#include <stdio.h>
#include <stdlib.h>

#include "buildNetwork.h"
#include "networkStructure.h"

#define MAX_NODES 1000

// Add node to the graph with specified id
AdjListNodeP createAdjacencyNode(int nodeNo) {
  AdjListNodeP newNode = (AdjListNodeP) malloc(sizeof(AdjListNode));

  if (!newNode) {
    printf("New node could not be created, unable to allocate needed memory");
    return NULL;
  }

  newNode->node = nodeNo;

  return newNode;
}


// Create new empty graph allocating nodes with no data
NetworkP createNetwork() {
  NetworkP newNetwork = (NetworkP)malloc(sizeof(Network));

  if (!newNetwork) {
    printf("New network could not be created, unable to allocate needed memory");
    return NULL;
  }

  newNetwork->noNodes = 0;
  newNetwork->adjacencyListArray = (AdjListP)malloc(MAX_NODES * sizeof(AdjList));

  if (!newNetwork->adjacencyListArray) {
    printf("New adjacency lisy array could not be created, unable to allocate needed memory");
    return NULL;
  }

  for (int x = 0; x < MAX_NODES; ++x) {
    newNetwork->adjacencyListArray[x].head = NULL;
    newNetwork->adjacencyListArray[x].noMembers = 0;
  }

  return newNetwork;
}


// Destroy graph, first removing adjacency nodes, then the adjacency array,
// then the network itself freeing up all memory
void destroyNetwork(NetworkP network) {
  if (network) {
    if (network->adjacencyListArray) {
      for (int x = 0; x < network->noNodes; ++x) {
        AdjListNodeP head = network->adjacencyListArray[x].head;

        while (head) {
          AdjListNodeP temp = head;
          head = head->next;
          free(temp);
        }
      }
      free(network->adjacencyListArray);
    }
    free(network);
  }
}


// Add new node to the network by adding the relevent data
void addNode(NetworkP network, int id, double x, double y) {
  AdjListP newNode = &network->adjacencyListArray[network->noNodes];

  newNode->id = id;
  newNode->x = x;
  newNode->y = y;

  network->noNodes++;
}

void addEdge(NetworkP network, int id, int source, int target, int weight) {

}
