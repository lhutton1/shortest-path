#ifndef __BUILDNETWORK__
#define __BUILDNETWORK__

#include "networkStructure.h"

AdjListNodeP createAdjacencyNode(int nodeNo);
NetworkP createNetwork();
void addNode(NetworkP network, int id, double x, double y);
void destroyNetwork(NetworkP network);

#endif
