#ifndef __WRITENETWORK__
#define __WRITENETWORK__

void writeNetwork(NetworkP network);
void writeEdge(FILE *fp, NetworkP network, AdjListP currentNode, AdjListP adjacentNode);

#endif
