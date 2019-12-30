#ifndef __BUILDNETWORK__
#define __BUILDNETWORK__

#include "networkStructure.h"

AdjListNodeP createAdjacencyNode(AdjListP node, double weight);
NetworkP createNetwork();
void addNode(NetworkP network, int id, double x, double y);
void destroyNetwork(NetworkP network);
void addEdge(NetworkP network, int id, int source, int target, double weight);

#endif
