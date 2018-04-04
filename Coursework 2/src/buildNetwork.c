#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "uthash.h"
#include "buildNetwork.h"
#include "networkStructure.h"
#include "constants.h"
#include "handleError.h"


// Add new adjacency node to the graph with specified id
AdjListNodeP createAdjacencyNode(AdjListP node, double weight) {
  AdjListNodeP newNode = (AdjListNodeP)malloc(sizeof(AdjListNode));

  if (!newNode)
    throwError("New node could not be created, unable to allocate needed memory");

  newNode->node = node->id;
  newNode->weight = weight;
  newNode->next = NULL;

  return newNode;
}


// Create new empty graph allocating adjacency nodes with no data
NetworkP createNetwork() {
  NetworkP newNetwork = (NetworkP)malloc(sizeof(Network));

  if (!newNetwork)
    throwError("New network could not be created, unable to allocate needed memory");

  newNetwork->noNodes = 0;
  newNetwork->adjacencyListArray = (AdjListP)malloc(MAX_NODES * sizeof(AdjList));
  newNetwork->nodesHashTable = NULL;

  if (!newNetwork->adjacencyListArray)
    throwError("New adjacency list array could not be created, unable to allocate needed memory");

  for (int x = 0; x < MAX_NODES; ++x) {
    newNetwork->adjacencyListArray[x].head = NULL;
    newNetwork->adjacencyListArray[x].noMembers = 0;
  }

  return newNetwork;
}


// Destroy graph, first removing adjacency nodes, then the adjacency array,
// then the network itself freeing up all memory.
void destroyNetwork(NetworkP network) {
  AdjListP currentNode, temp;

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
    }

    // delete and free all items in hash table
    HASH_CLEAR(hh,network->nodesHashTable);

    free(network->adjacencyListArray);
    free(network);
  }
}


// Add new node to the network by adding the relevent data to a free
// adjacency node. Also add this node to a hash table so it can
// be quickly found.
void addNode(NetworkP network, int id, double x, double y) {
  if (network->noNodes > MAX_NODES)
    throwError("Node limit reached - Please run the program again with fewer nodes");

  AdjListP newNode = &network->adjacencyListArray[network->noNodes];

  //Initialse new nodes properties
  newNode->noMembers = 0;
  newNode->id = id;
  newNode->x = x;
  newNode->y = y;
  newNode->head = NULL;
  newNode->path = false;

  HASH_ADD_INT(network->nodesHashTable, id, newNode);

  network->noNodes++;
}


// Add an edge to the network. Adds source node to the target in
// adjacency array and visa versa, using a linked list to keep
// track of changes.
void addEdge(NetworkP network, int id, int source, int target, double weight) {
  AdjListP sourceNode;
  AdjListP targetNode;

  HASH_FIND_INT(network->nodesHashTable, &source, sourceNode);
  HASH_FIND_INT(network->nodesHashTable, &target, targetNode);

  // Add node to adjacency list for source -> target (source | target, ...)
  AdjListNodeP newAdjNode = createAdjacencyNode(targetNode, weight);
  newAdjNode->next = sourceNode->head;
  sourceNode->head = newAdjNode;
  sourceNode->noMembers++;

  // Add node to adjacency list for target -> source (target | source, ...)
  newAdjNode = createAdjacencyNode(sourceNode, weight);
  newAdjNode->next = targetNode->head;
  targetNode->head = newAdjNode;
  targetNode->noMembers++;
}
