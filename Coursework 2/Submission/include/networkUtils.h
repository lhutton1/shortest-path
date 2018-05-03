#ifndef __NETWORKUTILS__
#define __NETWORKUTILS__

int getNodeIndex(NetworkP network, int id);
AdjListP getNode(NetworkP network, int id);
int getNodeOrder(NetworkP network, int nodeID);
double getEdgeWeight(NetworkP network, int sourceID, int targetID);
void deleteNode(NetworkP network, int nodeID);
void deleteEdge(NetworkP network, int sourceID, int targetID);

#endif
