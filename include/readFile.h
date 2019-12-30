#ifndef __READFILE__
#define __READFILE__

#include <stdbool.h>

void readFile(NetworkP network, char *filePath);
void parseLine(NetworkP network, char *line, bool findNode);

#endif
