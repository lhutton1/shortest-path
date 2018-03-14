#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "buildNetwork.h"
#include "readFile.h"

const int maxLineSize = 1000;

void readFile(NetworkP network, char *filePath) {
    FILE *file;

    if((file = fopen(filePath, "rb")) == NULL) {
        fprintf(stderr, "Error opening file: %s\n", filePath);
        return;
    }

    //begin to read file line by line and call parser
    char *line = malloc(maxLineSize);

    while (fgets(line, maxLineSize, file) != NULL) {
        parseLine(network, line);
        //printf("%s", line);
    }

    free(line);

    fclose(file);
}

void parseLine(NetworkP network, char *line) {
  int id;
  double lat;
  double lon;

  if (strncmp(line, "<node ", 6) == 0) {
    sscanf(line, "%*s id=%d lat=%lf lon=%lf", &id, &lat, &lon);
    addNode(network, id, lat, lon);

  } else if (strncmp(line, "<link ", 6) == 0) {
    //printf("Edge line found, %s\n", line);
  }
    //sscanf("", id, x, y);
}
