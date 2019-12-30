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
  double distance;                // distance of node from start node
  bool path;                    // is node part of a path?
  struct adjList *parent;       // parent node - djikstras
  struct adjListNode *head;     // head of linked adjacency list

  UT_hash_handle hh; /* Make structure hashable */

  /* To be able to use UT hash, this disclaimer must be included */
  /*Copyright (c) 2005-2016, Troy D. Hanson  http://troydhanson.github.com/uthash/
  All rights reserved.

  Redistribution and use in source and binary forms, with or without
  modification, are permitted provided that the following conditions are met:

      * Redistributions of source code must retain the above copyright
        notice, this list of conditions and the following disclaimer.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
  IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
  TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
  PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER
  OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
  EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
  PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
  PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
  LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
  NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.*/
};

typedef struct adjList AdjList, *AdjListP;

struct network {
  int noNodes;                  // number of nodes in the network
  AdjListP adjacencyListArray;  // array of nodes
  AdjListP nodesHashTable;      // hash table of nodes for quick access
};

typedef struct network Network, *NetworkP;



#endif
