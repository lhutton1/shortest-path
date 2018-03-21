#ifndef __BINARYHEAP__
#define __BINARYHEAP__

struct networkTuple {
  int priority;
  AdjListNodeP data;
};

typedef struct networkTuple NetworkTuple, *NetworkTupleP;

struct heap {
  int size;
  int count;
  NetworkTupleP *data;
};

typedef struct heap Heap, *HeapP;

HeapP createHeap();
void heapPush(HeapP heap, NetworkTupleP item);
NetworkTupleP heapPop(HeapP heap);
void destroyHeap(HeapP heap);
void heapifyDown(HeapP heap, int i);
void heapSwap(HeapP heap, int *x, int *y);
void printHeap(HeapP heap);

#endif
