#ifndef __DJIKSTRASALGORITHM__
#define __DJIKSTRASALGORITHM__

void dijkstrasAlgorithm(NetworkP network, int startID, int endID);
void resetNodes(NetworkP network);
void constructPath(NetworkP network, AdjListP end, AdjListP start);

#endif
