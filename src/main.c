#include "../include/treeStructure.h"
#include "../include/buildTree.h"
#include "../include/writeTree.h"
#include "../include/tests.h"


int main(int argc, char *argv[]) {
    printf("%d %c\n", argc, *argv[1]);
    if (argc == 2 && *argv[1] == '1') {
        printf("running test 1\n");
        task1();
    } else if (argc == 2 && *argv[1] == '2') {
        printf("running test 2\n");
    } else if (argc == 2 && *argv[1] == '3') {
        printf("running test 3\n");
    } else if (argc == 2 && *argv[1] == '4') {
        printf("running test 4\n");
    }
}