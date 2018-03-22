#ifndef __DJIKSTRASALGORITHM__
#define __DJIKSTRASALGORITHM__

void djikstrasAlgorithm(NetworkP network, int startID, int endID);
void resetNodes(NetworkP network);
void constructPath(NetworkP network, AdjListP currentNode, AdjListP end, AdjListP start);
void nodesToQueue(NetworkP network, PriorityQueue pq, AdjListP currentNode);

#endif
