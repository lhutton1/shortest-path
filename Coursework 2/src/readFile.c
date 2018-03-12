#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/networkStructure.h"
#define filePath "../resources/Final_Map.map"

const int maxLineSize = 1000;

void parseLine(char *line) {
  int id;
  double lat;
  double lon;

  if (strncmp(line, "<node ", 6) == 0) {
    sscanf()
  } else if (strncmp(line, "<link ", 6) == 0) {
    //printf("Edge line found, %s\n", line);
  }
    //sscanf("", id, x, y);
}

void readFile() {
    FILE *file;

    if((file = fopen(filePath, "rb")) == NULL) {
        fprintf(stderr, "Error opening file: %s\n", filePath);
        return;
    }

    //begin to read file line by line and call parser
    char *line = malloc(maxLineSize);

    while (fgets(line, maxLineSize, file) != NULL) {
        parseLine(line);
        //printf("%s", line);
    }

    free(line);

    fclose(file);
}



Node createNode() {

}

Edge createEdge() {

}
