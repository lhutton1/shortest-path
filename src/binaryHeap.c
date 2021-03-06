#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#include "networkStructure.h"
#include "binaryHeap.h"
#include "handleError.h"


// Create a new binary heap structure.
// This structure guarantees the value at index 0 to be the
// minimum out of the set.
HeapP createHeap() {
  HeapP heap = (HeapP)malloc(sizeof(Heap));

  if (!heap)
    throwError("Unable to allocate memory for new heap");

  heap->size = 4; //default size
  heap->count = 0;
  heap->data = malloc(sizeof(NetworkTuple) * heap->size);

  if (!heap->data)
    throwError("Unable to allocate memory for new heap data");

  return heap;
}


// Push item onto the heap and heapify item down heap until required
// position is reached.
void heapPush(HeapP heap, NetworkTuple newItem) {
  int itemIndex;
  int parentIndex;

  // if heap is too small, resize to allow more elements
  if (heap->size == heap->count) {
    heap->size <<= 1;
    heap->data = realloc(heap->data, sizeof(NetworkTuple) * heap->size);

    if (!heap)
      throwError("Unable to allocate more memory for heap data");
  }

  itemIndex = heap->count++;

  while (itemIndex) {
    parentIndex = (itemIndex - 1) >> 1;

    if (heap->data[parentIndex].priority <= newItem.priority)
      break;

    heap->data[itemIndex] = heap->data[parentIndex];
    itemIndex = parentIndex;
  }
  heap->data[itemIndex] = newItem;
}


// Pops the item with the minimum priority off the heap.
// Note: this is always at index 0
// Then calls heapifyDown to restructure the heap.
NetworkTuple heapPop(HeapP heap) {
  if (heap->count <= 0)
    throwError("Unable to pop from an empty queue");

  NetworkTuple head = heap->data[0];
  heap->data[0] = heap->data[--heap->count];

  // resize heap if too many elements have been removed
  if ((heap->count <= (heap->size >> 2)) && (heap->size > 4)) {
    heap->size >>= 1;
    heap->data = realloc(heap->data, sizeof(NetworkTuple) * heap->size);

    if (!heap->data)
      throwError("Unable to reallocate less memory for heap data");
  }

  heapifyDown(heap, 0);
  return head;
}


// Restructures the heap from given index. If the item is greater than
// any of its chlid nodes, swap the item with it's smallest node.
// This step is repeated until the item reaches its correct position.
void heapifyDown(HeapP heap, int i) {
  int smallest = i;
  int l, r;

  while (true) {
    l = (2*i + 1);
    r = (2*i + 2);

    if (l < heap->count && heap->data[l].priority < heap->data[r].priority)
      smallest = l;
    if (r < heap->count && heap->data[r].priority < heap->data[smallest].priority)
      smallest = r;

    if (smallest == i)
      break;

    heapSwap(heap, &i, &smallest);
    i = smallest;
  }
}


// Small function to swap two items in the heap array
void heapSwap(HeapP heap, int *x, int *y) {
  NetworkTuple temp = heap->data[*x];
  heap->data[*x] = heap->data[*y];
  heap->data[*y] = temp;
}


// Output heap - for debugging purposes
void printHeap(HeapP heap) {
  for (int x = 0; x < heap->count; x++)
    printf("(%lf, %d), ", heap->data[x].priority, x);

  printf("\n");
}


// Destroy heap, freeing up all used memeory
void destroyHeap(HeapP heap) {
  if (heap) {
    free(heap->data);
    free(heap);
  }
}
