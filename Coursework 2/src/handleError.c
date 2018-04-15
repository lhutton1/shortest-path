#include <stdlib.h>
#include <stdio.h>

// Small function to handle errors.
// Prints error message and exits program,
// taking care of memory leaks
void throwError(char *errorMsg) {
  printf("The program ran into an error and was forced to stop:\n");
  printf("Error: %s\n\n", errorMsg);
  exit(1);
}
