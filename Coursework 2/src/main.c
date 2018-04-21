#include <stdio.h>
#include <stdlib.h>

#include "buildNetwork.h"
#include "readFile.h"
#include "networkStructure.h"
#include "networkUtils.h"
#include "binaryHeap.h"
#include "priorityQueue.h"
#include "dijkstrasAlgorithm.h"
#include "writeNetwork.h"
#include "constants.h"
#include "handleError.h"

const int MAX_NODES = 4000;
const int MAX_LINE_SIZE = 1000;
const char *PATH_EDGE_COLOUR = "0xFF0000";
const char *EDGE_COLOUR = "0x0000FF";

int main(int argc, char *argv[]) {
  char *filePath;
  int startID;
  int endID;

  if (argc <= 3)
    throwError("Missing arguments 'filePath, start node ID, end node ID'");

  filePath = argv[1];
  startID = atoi(argv[2]);
  endID = atoi(argv[3]);

  NetworkP n = createNetwork();
  readFile(n, filePath);

  dijkstrasAlgorithm(n, startID, endID);
  writeNetwork(n);
  destroyNetwork(n);

  // print spacer
  printf("\n");

  return 0;
}
