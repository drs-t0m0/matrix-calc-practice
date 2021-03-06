#!/bin/bash

#gcc main.c -o main && ./main 1000 && ./main 3000 && ./main 4000

#gcc main.c -o main &&
#./main 100 &&
#./main 200 &&
#./main 300 &&
#./main 400 &&
#./main 500 &&
#./main 600 &&
#./main 700 &&
#./main 800 &&
#./main 900 &&
#./main 1000

#gcc main.c -O3 -march=native -mavx2 -o main && ./main 1000
gcc main.c -O3 -o main && ./main 3
