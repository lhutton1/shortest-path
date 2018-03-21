#include <stdio.h>
#include <stdbool.h>

#include "buildNetwork.h"
#include "readFile.h"
#include "networkStructure.h"
#include "networkUtils.h"
#include "binaryHeap.h"
#include "priorityQueue.h"

int main(void) {
  NetworkP n = createNetwork();
  readFile(n, "resources/Final_Map.map", true);   //pass1
  readFile(n, "resources/Final_Map.map", false);  //pass2

  PriorityQueue q = createPQueue();
  queuePush(q, 2, NULL);
  queuePush(q, 3, NULL);
  queuePush(q, 6, NULL);
  queuePush(q, 8, NULL);
  queuePush(q, 9, NULL);
  queuePush(q, 3, NULL);
  queuePush(q, 1, NULL);
  printQueue(q);
  printf("%p\n", queuePop(q));
  printf("%p\n", queuePop(q));
  printf("%p\n", queuePop(q));
  printf("%p\n", queuePop(q));
  printf("%p\n", queuePop(q));
  printf("%p\n", queuePop(q));
  printQueue(q);
  destroyPQueue(q);

  destroyNetwork(n);

  return 0;
}
