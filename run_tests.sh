#! /bin/bash

mkdir -p outputs
gcc -c test/*.c list.c
gcc -o outputs/test.out *.o
rm -rf *.o
./outputs/test.out