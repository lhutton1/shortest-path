#include <stdio.h>

#include "buildNetwork.h"
#include "readFile.h"
#include "networkStructure.h"

int main(void) {
  NetworkP n = createNetwork();
  readFile(n, "resources/Final_Map.map");
  printf("finished\n");
  printf("%d\n", n->adjacencyListArray[0].id);
  printf("%lf\n", n->adjacencyListArray[0].x);
  printf("%lf\n", n->adjacencyListArray[0].y);
  destroyNetwork(n);

  return 0;
}
