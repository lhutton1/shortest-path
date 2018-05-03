#!/bin/bash

# remove all existing images in test folder
rm -f test/*.png

# test wrong file name
echo "*TEST 1*"
./out/main "resources/abc.map" 0 0 &&\
{ gnuplot -e "set output 'test/test1.png'; load 'out/network.gnu';"; }

# running 'main' with no parameters
echo "*TEST 2*"
./out/main &&\
{ gnuplot -e "set output 'test/test2.png'; load 'out/network.gnu';"; }

# disconnected graph
echo "*TEST 3*"
./out/main "resources/DisconnectedMap.map" 1 7 &&\
{ gnuplot -e "set output 'test/test3.png'; load 'out/network.gnu';"; }

# non existant node ID's, (on the final large data set)
echo "*TEST 4*"
./out/main "resources/Final_Map.map" -1 1 &&\
{ gnuplot -e "set output 'test/test4.png'; load 'out/network.gnu';"; }

# simple map test
echo "*TEST 5*"
echo "Expected Path: 1-2-5-4"
./out/main "resources/SimpleMap.map" 1 4 &&\
{ gnuplot -e "set output 'test/test5.png'; load 'out/network.gnu';"; }

# simple map test
echo "*TEST 6*"
echo "Expected Path: 6-1-2"
./out/main "resources/SimpleMap.map" 6 2 &&\
{ gnuplot -e "set output 'test/test6.png'; load 'out/network.gnu';"; }

# wrong type node ID's
echo "*TEST 7*"
./out/main "resources/Final_Map.map" "adf" "dhfgfdj" &&\
{ gnuplot -e "set output 'test/test7.png'; load 'out/network.gnu';"; }

# same start and end nodes
echo "*TEST 8*"
./out/main "resources/Final_Map.map" -2524 -2524 &&\
{ gnuplot -e "set output 'test/test8.png'; load 'out/network.gnu';"; }

# simple path between two adjacent nodes
echo "*TEST 9*"
echo "Expected Path: 1967343264-1615401915"
./out/main "resources/Final_Map.map" 1967343264 1615401915 &&\
{ gnuplot -e "set output 'test/test9.png'; load 'out/network.gnu';"; }

# medium sized path
echo "*TEST 10*"
echo "Expected Path: -2562,-2560,1187324666,1187324679,54060643,54060637,985096817,985096821,985096825,-2416,-2380"
./out/main "resources/Final_Map.map" -2562 -2380 &&\
{ gnuplot -e "set output 'test/test10.png'; load 'out/network.gnu';"; }

# large path between two nodes
echo "*TEST 11*"
echo "Expected Path: -2524,-2540,247958669,247958668,301673229,247958643,247958642,247958641,247958640,247958645,247958646,247958647,247958648,247958649,247958650,247958651,247958653,247958654,301673241,247958598,247958611,247958610,247958608,247958607,247958606,247958605,247958604,301673248,247958601,247958600,247958599,247293219,-2502,247293220,247293215,985096764,985096813,985096817,54060637,54060643,1187324679,1187324666,-2560,1187324670,1187324682,1187324692,1187324676,1187324678,1187324665,1187324690,984231425,54060524,984231603,54060515,54060547,54060551,1725582974,54060555,54060557,1668111641,1668111640"
./out/main "resources/Final_Map.map" -2524 1668111640 &&\
{ gnuplot -e "set output 'test/test11.png'; load 'out/network.gnu';"; }
