#include <stdio.h>
#include <stdbool.h>

#include "buildNetwork.h"
#include "readFile.h"
#include "networkStructure.h"

int main(void) {
  NetworkP n = createNetwork();
  readFile(n, "resources/Final_Map.map", true);   //pass1
  readFile(n, "resources/Final_Map.map", false);  //pass2
  printf("%d\n", n->adjacencyListArray[0].id);
  printf("%d\n", n->adjacencyListArray[0].noMembers);
  printf("%d\n", n->adjacencyListArray[0].head->node);
  printf("%lf\n", n->adjacencyListArray[0].head->weight);
  printf("%lf\n", n->adjacencyListArray[0].head->next->weight);
  printf("%lf\n", n->adjacencyListArray[0].head->next->next->weight);

  destroyNetwork(n);

  return 0;
}
