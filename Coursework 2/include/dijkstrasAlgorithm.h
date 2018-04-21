<<<<<<< HEAD
#ifndef __DJIKSTRASALGORITHM__
#define __DJIKSTRASALGORITHM__

void dijkstrasAlgorithm(NetworkP network, int startID, int endID);
void resetNodes(NetworkP network);
void constructPath(NetworkP network, AdjListP end, AdjListP start);
void nodesToQueue(NetworkP network, PriorityQueue pq, AdjListP currentNode);

#endif
=======
#ifndef __DJIKSTRASALGORITHM__
#define __DJIKSTRASALGORITHM__

void dijkstrasAlgorithm(NetworkP network, int startID, int endID);
void resetNodes(NetworkP network);
void constructPath(NetworkP network, AdjListP end, AdjListP start);

#endif
>>>>>>> 63e7d4b3330942b42e10914e6614ed9f77778ada
