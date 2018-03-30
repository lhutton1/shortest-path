#ifndef __NETWORKSTRUCTURE__
#define __NETWORKSTRUCTURE__

#include <stdbool.h>
#include "uthash.h"

struct adjListNode {
  int node;                     // id of node
  double weight;                // weight of path between adgacency item and current node
  struct adjListNode *next;     // pointer to next adjacency item
};

typedef struct adjListNode AdjListNode, *AdjListNodeP;

struct adjList {
  int noMembers;                // records number of adjacent nodes to current node
  int id;                       // id of node
  double x;                     // x position of node on map
  double y;                     // y position of node on map
  double distance;              // distance of node from start node
  bool path;                    // is node part of a path?
  struct adjList *parent;       // parent node - djikstras
  struct adjListNode *head;     // head of linked adjacency list

  UT_hash_handle hh; /* Make structure hashable */
};

typedef struct adjList AdjList, *AdjListP;

struct network {
  int noNodes;                  // number of nodes in the network
  AdjListP adjacencyListArray;  // array of nodes
  AdjListP nodesHashTable;      // hash table of nodes for quick access
};

typedef struct network Network, *NetworkP;

#endif
