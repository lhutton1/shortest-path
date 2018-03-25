#ifndef __NETWORKSTRUCTURE__
#define __NETWORKSTRUCTURE__

#include <stdbool.h>
#include "uthash.h"

struct adjListNode {
  int node;
  double weight;
  struct adjListNode *next;
};

typedef struct adjListNode AdjListNode, *AdjListNodeP;

struct adjList {
  int noMembers;                // records number of adjacent nodes to current node
  int id;                       // id of node
  int index;                    // index of node in the adjacency list
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
  int noNodes;
  AdjListP adjacencyListArray;
  AdjListP nodesHashTable;
};

typedef struct network Network, *NetworkP;

#endif
