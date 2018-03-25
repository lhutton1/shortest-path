#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#include "buildNetwork.h"
#include "readFile.h"
#include "networkStructure.h"
#include "networkUtils.h"
#include "binaryHeap.h"
#include "priorityQueue.h"
#include "djikstrasAlgorithm.h"
#include "writeNetwork.h"

int main(void) {
  printf("starting...\n");
  NetworkP n = createNetwork();
  readFile(n, "resources/Final_Map.map", true);   //pass1
  readFile(n, "resources/Final_Map.map", false);  //pass2
  printf("read complete...\n");

  djikstrasAlgorithm(n, 247293164, -1851654833);
  writeNetwork(n);

  destroyNetwork(n);

  return 0;
}
