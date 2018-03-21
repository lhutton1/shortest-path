#ifndef __PRIORITYQUEUE__
#define __PRIORITYQUEUE__

typedef HeapP PriorityQueue;

HeapP createPQueue();
void queuePush(HeapP heap, int priority, AdjListNodeP data);
AdjListNodeP queuePop(HeapP heap);
AdjListNodeP queuePeek(HeapP heap);
void printQueue(HeapP heap);
bool queueIsEmpty(HeapP heap);
void destroyPQueue(HeapP heap);

#endif
