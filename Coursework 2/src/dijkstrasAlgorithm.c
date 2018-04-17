#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#include "networkStructure.h"
#include "networkUtils.h"
#include "priorityQueue.h"
#include "dijkstrasAlgorithm.h"
#include "handleError.h"


// Djikstras algorithm calculates the shortest path between
// two nodes on the network.
// In this function we reverse the the start and end nodes.
// this means that the path is output in the correct order,
// i.e from start to finish.
void dijkstrasAlgorithm(NetworkP network, int startID, int endID) {
  PriorityQueue pq = createPQueue();
  AdjListP start = getNode(network, endID);
  AdjListP end = getNode(network, startID);
  AdjListP currentNode;
  AdjListP nextNode;
  AdjListNodeP currentEdge;

  if (start == NULL)
    throwError("Node ID could not be found, please ensure the node exists");

  if (startID == endID)
    throwError("Start node cannot be the same as the end node");

  resetNodes(network);
  start->distance = 0;
  queuePush(pq, start->distance, start);

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
  for (int x = 0; x < network->noNodes; x++) {
    network->adjacencyListArray[x].distance = INFINITY;
  }
}


// Construct a path after running the initial algorithm.
// A path is created using each nodes parent.
void constructPath(NetworkP network, AdjListP end, AdjListP start) {
  AdjListP currentNode = end;
  printf("Path distance: %lf\n", currentNode->distance);
  printf("---------PATH----------\n");
  while (currentNode != start) {
    printf("ID:%d, X:%lf, Y:%lf\n", currentNode->id, currentNode->x, currentNode->y);
    currentNode->path = true;

    if (currentNode->parent)
      currentNode = currentNode->parent;
    else
      throwError("Path cannot be completed because a node is disconnected from the network");
  }
  printf("ID:%d, X:%lf, Y:%lf\n", start->id, start->x, start->y);
  start->path = true;
  printf("-----------------------\n");
}
