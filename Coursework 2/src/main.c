#include <stdio.h>
#include <stdbool.h>

#include "buildNetwork.h"
#include "readFile.h"
#include "networkStructure.h"
#include "networkUtils.h"

int main(void) {
  NetworkP n = createNetwork();
  readFile(n, "resources/Final_Map.map", true);   //pass1
  readFile(n, "resources/Final_Map.map", false);  //pass2

  deleteEdge(n, 1968799687, 1970536626);
  printf("%lf\n", getEdgeWeight(n, 1968799687, 1970536626));

  destroyNetwork(n);

  return 0;
}
