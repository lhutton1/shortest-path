#ifndef _TREESTRUCTURE_
#define _TREESTRUCTURE_

struct qnode {
  int level;
  double xy[2];
  struct qnode *child[4];
};

typedef struct qnode Node;

#endif
