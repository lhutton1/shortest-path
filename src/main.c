#include "../include/tests.h"


int main(int argc, char *argv[]) {
    if (argc == 2 && *argv[1] == '1') {
        task1();
    } else if (argc == 2 && *argv[1] == '2') {
        task2();
    } else if (argc == 2 && *argv[1] == '3') {
        task3();
    } else if (argc == 2 && *argv[1] == '4') {
        task4();
    }
}