#!/bin/bash

# remove all existing images in test folder
rm -f test/*.png

# non existant node ID's, (on the final large data set)
echo "*TEST 1*"
./out/main "resources/Final_Map.map" -1 1 &&\
{ gnuplot -e "set output 'test/test1.png'; load 'out/network.gnu';"; }

# simple map
echo "*TEST 2*"
./out/main "resources/SimpleMap.map" 1 4 &&\
{ gnuplot -e "set output 'test/test1.png'; load 'out/network.gnu';"; }

# wrong type node ID's
echo "*TEST 3*"
./out/main "resources/Final_Map.map" "adf" "dhfgfdj" &&\
{ gnuplot -e "set output 'test/test2.png'; load 'out/network.gnu';"; }

# simple path between two adjacent nodes
echo "*TEST 4*"
./out/main "resources/Final_Map.map" 1967343264 1615401915 &&\
{ gnuplot -e "set output 'test/test3.png'; load 'out/network.gnu';"; }

# large path between two nodes
echo "*TEST 5*"
./out/main "resources/Final_Map.map" -2524 1668111640 &&\
{ gnuplot -e "set output 'test/test4.png'; load 'out/network.gnu';"; }
