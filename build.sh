#!/bin/bash

echo build last stage 
gcc -o m3 ./src/m3.c ./src/chainloader.c
strip m3
./m3 9
./bin2c.py m3 3
mv ./m3.h ./src/
 
echo build 3rd stage
gcc -o m2 ./src/m2.c ./src/chainloader.c
strip m2
./m2 39
./bin2c.py m2 11
mv ./m2.h ./src/

echo build 2nd stage
gcc -o m1 ./src/m1.c ./src/chainloader.c
strip m1
./m1 b39
./bin2c.py m1 15
mv ./m1.h ./src/

echo build gates
gcc -o matryoshka ./src/m0.c ./src/chainloader.c
strip matryoshka
echo launching...
./matryoshka


