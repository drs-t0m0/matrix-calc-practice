#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <sys/time.h>

void CreateMatrix(int *matrix, int N) {
    for (int i = 0; i < N * N; i++) {
        matrix[i] = i + 1;
    }
}

void CalculateMatrix(int *matrix1, int *matrix2, int *matrix3, int N) {
    for (int j = 0; j < N; ++j) {
        for (int i = 0; i < N; ++i) {
            int sum = 0;
            for (int k = 0; k < N; ++k) {
                sum += matrix1[i * N + k] * matrix2[k * N + j];
            }
            matrix3[i * N + j] = sum;
        }
    }
}

void MeasureCreateTime(void (*pf)(int *, int), int *matrix1, int *matrix2, int *matrix3, int N) {
    struct timeval stv, etv;
    gettimeofday(&stv, NULL);

    printf("create time\n");
    pf(matrix1, N);
    pf(matrix2, N);
    pf(matrix3, N);

    gettimeofday(&etv, NULL);

    printf("%ld.%06lu\n", etv.tv_sec - stv.tv_sec, etv.tv_usec - stv.tv_usec);
}

void MeasureCalculateTime(void (*pf)(int *, int *, int *, int), int *matrix1, int *matrix2, int *matrix3, int N) {
    struct timeval stv, etv;
    gettimeofday(&stv, NULL);

    printf("calculate time\n");
    pf(matrix1, matrix2, matrix3, N);

    gettimeofday(&etv, NULL);

    printf("%ld.%06lu\n", etv.tv_sec - stv.tv_sec, etv.tv_usec - stv.tv_usec);
}

int main(int argc, char *argv[]) {
    int N = atoi(argv[1]);
    printf("----------\n");
    printf("main start, args: %d\n", N);

    struct timeval stv, etv;
    gettimeofday(&stv, NULL);
    int *matrix1 = (int *) malloc(N * N * sizeof(int));
    int *matrix2 = (int *) malloc(N * N * sizeof(int));
    int *matrix3 = (int *) malloc(N * N * sizeof(int));
    gettimeofday(&etv, NULL);
    printf("malloc time\n");
    printf("%ld.%06lu\n", etv.tv_sec - stv.tv_sec, etv.tv_usec - stv.tv_usec);

    MeasureCreateTime(CreateMatrix, matrix1, matrix2, matrix3, N);
    MeasureCalculateTime(CalculateMatrix, matrix1, matrix2, matrix3, N);

    printf("main end\n");
    return 0;
}