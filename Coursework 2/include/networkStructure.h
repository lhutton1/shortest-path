#ifndef __NETWORKSTRUCTURE__
#define __NETWORKSTRUCTURE__

#include "uthash.h"

struct adjListNode {
  int node;
  double weight;
  struct adjListNode *next;
};

typedef struct adjListNode AdjListNode, *AdjListNodeP;

struct adjList {
  int noMembers;
  int id;
  int index;
  double x;
  double y;
  struct adjListNode *head;

  UT_hash_handle hh; /* Make structure hashable */
};

typedef struct adjList AdjList, *AdjListP;

struct network {
  int noNodes;
  AdjListP adjacencyListArray;
};

typedef struct network Network, *NetworkP;

#endif
