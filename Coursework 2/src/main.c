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
#include "constants.h"

const int MAX_NODES = 4000;
const int MAX_LINE_SIZE = 1000;
const char *PATH_EDGE_COLOUR = "0xFF0000";
const char *EDGE_COLOUR = "0x0000FF";

int main(void) {
  NetworkP n = createNetwork();
  readFile(n, "resources/Final_Map.map");

  djikstrasAlgorithm(n, 247293164, -1851654833);
  printf("Writing network...\n");
  writeNetwork(n);

  destroyNetwork(n);

  return 0;
}
