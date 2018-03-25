#include <stdio.h>

#include "networkStructure.h"
#include "uthash.h"


// Get node by ID. Get hash of node and return
// node if found.
AdjListP getNode(NetworkP network, int id) {
  AdjListP node;
  HASH_FIND_INT(network->nodesHashTable, &id, node);

  if (node != NULL)
    return node;
  else
    return NULL;
}


// Get node order from given node ID
int getNodeOrder(NetworkP network, int nodeID) {
  AdjListP node = getNode(network, nodeID);
  return node->noMembers;
}


// Get edge weight from given source node ID and target
// node ID and return the weight. If not found return -1
double getEdgeWeight(NetworkP network, int sourceID, int targetID) {
  if (sourceID != targetID) {
    AdjListNodeP node;
    AdjListP source = getNode(network, sourceID);

    node = source->head;

    while (node != NULL) {
      if (node->node == targetID)
        return node->weight;

      node = node->next;
    }
  }
  return -1;
}


// Delete node from given ID. Remove node value from hash.
void deleteNode(NetworkP network, int nodeID) {
  AdjListP node = getNode(network, nodeID);

  if (!node)
    return;

  HASH_DEL(network->nodesHashTable, node);
}
