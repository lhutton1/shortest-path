#ifndef __BINARYHEAP__
#define __BINARYHEAP__

struct networkTuple {
  double priority;
  AdjListP data;
};

typedef struct networkTuple NetworkTuple, *NetworkTupleP;

struct heap {
  int size;
  int count;
  NetworkTuple *data;
};

typedef struct heap Heap, *HeapP;

HeapP createHeap();
void heapPush(HeapP heap, NetworkTuple item);
NetworkTuple heapPop(HeapP heap);
void destroyHeap(HeapP heap);
void heapifyDown(HeapP heap, int i);
void heapSwap(HeapP heap, int *x, int *y);
void printHeap(HeapP heap);

#endif
