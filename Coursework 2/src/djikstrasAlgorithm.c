#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#include "networkStructure.h"
#include "networkUtils.h"
#include "priorityQueue.h"
#include "djikstrasAlgorithm.h"
#include "handleError.h"


// Djikstras algorithm calculates the shortest path between
// two nodes on the network.
void djikstrasAlgorithm(NetworkP network, int startID, int endID) {
  PriorityQueue pq = createPQueue();
  AdjListP start = getNode(network, startID);
  AdjListP end = getNode(network, endID);
  AdjListP currentNode;
  AdjListP nextNode;
  AdjListNodeP currentEdge;

  if (startID == endID)
    throwError("Start node cannot be the same as the end node");

  resetNodes(network);
  start->distance = 0;
  nodesToQueue(network, pq, currentNode);

  while (!queueIsEmpty(pq)) {
    currentNode = queuePop(pq);

    if (currentNode == end) break;
    currentEdge = currentNode->head;

    // Loop through adjacent nodes
    while (currentEdge != NULL) {
      nextNode = getNode(network, currentEdge->node);

      if (currentNode->distance + currentEdge->weight < nextNode->distance) {
        nextNode->distance = currentNode->distance + currentEdge->weight;
        nextNode->parent = currentNode;
        queuePush(pq, nextNode->distance, nextNode);
      }
      currentEdge = currentEdge->next;
    }
  }
  constructPath(network, end, start);
  destroyPQueue(pq);
}


// Before djikstras algorithm can start all nodes must have a
// distance of infinity except the start node. 'INFINITY' is a constant
// defined in 'math.h'.
void resetNodes(NetworkP network) {
  for (int x = 0; x < network->noNodes - 1; x++)
    network->adjacencyListArray[x].distance = INFINITY;
}


// Construct a path after running the initial algorithm.
// A path is created using each nodes parent.
void constructPath(NetworkP network, AdjListP end, AdjListP start) {
  AdjListP currentNode = end;

  printf("Path Distance: %lf\n", currentNode->distance);
  printf("-----PATH-----\n");
  while (currentNode != start) {
    printf("ID:%d, X:%lf, Y:%lf\n", currentNode->id, currentNode->x, currentNode->y);
    currentNode->path = true;
    currentNode = currentNode->parent;
  }
  printf("--------------\n");
}


// Add all nodes to the queue using heapify.
void nodesToQueue(NetworkP network, PriorityQueue pq, AdjListP currentNode) {
  for (int x = 0; x < network->noNodes - 1; x++) {
    currentNode = &network->adjacencyListArray[x];
    queuePush(pq, currentNode->distance, currentNode);
  }
}
