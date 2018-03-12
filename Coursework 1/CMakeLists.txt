cmake_minimum_required(VERSION 3.9)
project(comp1921)

set(CMAKE_CXX_STANDARD 11)

add_executable(comp1921
        src/buildTree.c
        include/buildTree.h
        src/main.c
        Makefile
        src/tests.c
        include/treeStructure.h
        src/writeTree.c
        include/writeTree.h src/destroyTree.c include/destroyTree.h src/growTree.c include/growTree.h include/tests.h src/valueTree.c include/valueTree.h)
