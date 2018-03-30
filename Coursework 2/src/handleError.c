
// Small function to handle errors.
// Prints error message and exits program,
// taking care of memory leaks
void throwError(char *errorMsg) {
  printf("%s\n", errorMsg);
  exit(1);
}
