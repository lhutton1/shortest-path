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

int main(void) {
  NetworkP n = createNetwork();
  readFile(n, "resources/Final_Map.map", true);   //pass1
  readFile(n, "resources/Final_Map.map", false);  //pass2

  djikstrasAlgorithm(n, 52728502, 31004231);

  destroyNetwork(n);

  return 0;
}
