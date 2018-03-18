#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "buildNetwork.h"
#include "readFile.h"


// Open file and read line by line, limit line size to
// maxLineSize preventing overflow
const int MAX_LINE_SIZE = 1000;

void readFile(NetworkP network, char *filePath, bool findNode) {
    FILE *file;

    if((file = fopen(filePath, "rb")) == NULL) {
        fprintf(stderr, "Error opening file: %s\n", filePath);
        return;
    }

    //begin to read file line by line and call parser
    char *line = malloc(MAX_LINE_SIZE);

    while (fgets(line, MAX_LINE_SIZE, file) != NULL)
        parseLine(network, line, findNode);

    free(line);
    fclose(file);
}


// Parse each line in the file. Check whether line is a node or edge,
// then perform the relevent action such as 'addNode' or 'addEdge'.
void parseLine(NetworkP network, char *line, bool findNode) {
  int id;
  double lat;
  double lon;
  int source;
  int target;
  double weight;

  if (findNode == true && strncmp(line, "<node ", 6) == 0) {
    sscanf(line, "%*s id=%d lat=%lf lon=%lf", &id, &lat, &lon);
    addNode(network, id, lat, lon);
  } else if (findNode == false && strncmp(line, "<link ", 6) == 0) {
    sscanf(line, "%*s id=%d node=%d node=%d %*s length=%lf", &id, &source, &target, &weight);
    //printf("adding edge: %d, %d, %d, %lf\n", id, source, target, weight);
    addEdge(network, id, source, target, weight);
  }
    //sscanf("", id, x, y);
}
