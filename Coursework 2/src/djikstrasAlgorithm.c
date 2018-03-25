#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#include "networkStructure.h"
#include "networkUtils.h"
#include "priorityQueue.h"
#include "djikstrasAlgorithm.h"


void djikstrasAlgorithm(NetworkP network, int startID, int endID) {
  PriorityQueue pq = createPQueue();
  AdjListP start = getNode(network, startID);
  AdjListP end = getNode(network, endID);
  AdjListP currentNode;
  AdjListP nextNode;
  AdjListNodeP currentEdge;

  if (startID == endID) {
    printf("Start node cannot be the same as the end node\n");
    return;
  }

  resetNodes(network);
  start->distance = 0;
  nodesToQueue(network, pq, currentNode);

  while (!queueIsEmpty(pq)) {
    currentNode = queuePop(pq);

    if (currentNode == end) break;
    currentEdge = currentNode->head;

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
  constructPath(network, currentNode, end, start);
  destroyPQueue(pq);
}

void resetNodes(NetworkP network) {
  for (int x = 0; x < network->noNodes - 1; x++) {
    network->adjacencyListArray[x].distance = INFINITY;
    network->adjacencyListArray[x].parent = NULL;
  }
}

void constructPath(NetworkP network, AdjListP currentNode, AdjListP end, AdjListP start) {
  double pathDist = 0;

  currentNode = end;
  pathDist = currentNode->distance;
  printf("Path Distance: %lf\n", pathDist);
  printf("-----PATH-----\n");
  while (currentNode != start) {
    printf("%d\n", currentNode->id);
    currentNode->path = true;
    currentNode = currentNode->parent;
  }
  printf("--------------\n");
}

void nodesToQueue(NetworkP network, PriorityQueue pq, AdjListP currentNode) {
  for (int x = 0; x < network->noNodes - 1; x++) {
    currentNode = &network->adjacencyListArray[x];
    queuePush(pq, currentNode->distance, currentNode);
  }
}
