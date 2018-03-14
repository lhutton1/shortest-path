#ifndef __NETWORKSTRUCTURE__
#define __NETWORKSTRUCTURE__

struct adjListNode {
  int node;
  double weight;
  struct adjListNode *next;
};

typedef struct adjListNode AdjListNode, *AdjListNodeP;

struct adjList {
  int noMembers;
  int id;
  double x;
  double y;
  struct adjListNode *head;
};

typedef struct adjList AdjList, *AdjListP;

struct network {
  int noNodes;
  AdjListP adjacencyListArray;
};

typedef struct network Network, *NetworkP;

#endif
