#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#include "networkStructure.h"
#include "binaryHeap.h"
#include "priorityQueue.h"


// Create new priority queue by creating a
// new instance of heap.
HeapP createPQueue() {
  return createHeap();
}


// Push an item onto the queue with given priority
// the queue will then reorder the elements in the heap
// to make sure the item at index 0 has the minimum priority
void queuePush(HeapP heap, double priority, AdjListP data) {
  NetworkTupleP dataTuple = (NetworkTupleP)malloc(sizeof(NetworkTuple));

  dataTuple->priority = priority;
  dataTuple->data = data;

  // push data onto heap
  heapPush(heap, dataTuple);

  //free(dataTuple);
}


// Pop item with the lowest priority from the queue
AdjListP queuePop(HeapP heap) {
  return heapPop(heap)->data;
}


// Peek at the item with the lowest priority in the queue
// but don't remove it.
AdjListP queuePeek(HeapP heap) {
  return heap->data[0]->data;
}


// Check to see if the queue has any items left in it
bool queueIsEmpty(HeapP heap) {
  return heap->count ? false : true;
}


// Output the queue - index, priority, pointer to data
void printQueue(HeapP heap) {
  printf("----Queue----\n");
  for (int x = 0; x < heap->count; x++)
    printf("%d: (%lf, %p)\n", x, heap->data[x]->priority, heap->data[x]->data);
  printf("-------------\n");
}


// Destroy the queue, freeing memeory
void destroyPQueue(HeapP heap) {
  destroyHeap(heap);
}
