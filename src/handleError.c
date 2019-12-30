#include <stdlib.h>
#include <stdio.h>

#include "buildNetwork.h"
#include "networkStructure.h"

// Small function to handle errors.
// Prints error message and exits program
void throwError(char *errorMsg) {
  printf("The program ran into an error and was forced to stop:\n");
  printf("Error: %s\n\n", errorMsg);
  exit(1);
}
