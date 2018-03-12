#ifndef __NETWORKSTRUCTURE__
#define __NETWORKSTRUCTURE__

struct node {
  int id;
  double lat;
  double lon;
};

typedef struct node Node;

struct edge {
  int id;
  int nodeid[2];
};

typedef struct edge Edge;

#endif
