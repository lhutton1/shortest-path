#ifndef __PRIORITYQUEUE__
#define __PRIORITYQUEUE__

#include <stdbool.h>
#include "binaryHeap.h"

typedef HeapP PriorityQueue;

HeapP createPQueue();
void queuePush(HeapP heap, double priority, AdjListP data);
AdjListP queuePop(HeapP heap);
AdjListP queuePeek(HeapP heap);
void printQueue(HeapP heap);
bool queueIsEmpty(HeapP heap);
void destroyPQueue(HeapP heap);

#endif
