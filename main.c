#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <omp.h>

void createMatrix(double *matrix, int N) {
#pragma omp parallel for
    for (int i = 0; i < N * N; i++) {
        matrix[i] = i + 1;
    }
}

void calculateMatrix(double *matrix1, double *matrix2, double *matrix3, int N) {
#pragma omp parallel for
    for (int j = 0; j < N; ++j) {
        for (int i = 0; i < N; ++i) {
            double sum = 0;
            for (int k = 0; k < N; ++k) {
                sum += matrix1[i * N + k] * matrix2[k * N + j];
            }
            matrix3[i * N + j] = sum;
        }
    }
}

void measureCreateTime(void (*pf)(double *, int), double *matrix1, double *matrix2, double *matrix3, int N) {
    struct timeval stv, etv;
    gettimeofday(&stv, NULL);

    printf("create time\n");
    pf(matrix1, N);
    pf(matrix2, N);
    pf(matrix3, N);

    gettimeofday(&etv, NULL);

    printf("%ld.%06lu\n", etv.tv_sec - stv.tv_sec, etv.tv_usec - stv.tv_usec);
}

void measureCalculateTime(void (*pf)(double *, double *, double *, int), double *matrix1, double *matrix2, double *matrix3, int N) {
    struct timeval stv, etv;
    gettimeofday(&stv, NULL);

    printf("calculate time\n");
    pf(matrix1, matrix2, matrix3, N);

    gettimeofday(&etv, NULL);

    printf("%ld.%06lu\n", etv.tv_sec - stv.tv_sec, etv.tv_usec - stv.tv_usec);
}

void outputMatrix(double *matrix, int N) {
    FILE *outputfile;
    outputfile = fopen("output.txt", "w");
    if (outputfile == NULL) {
        printf("output error\n");
        exit(1);
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            fprintf(outputfile, "%f ", matrix[i * N + j]);
        }
        fprintf(outputfile, "\n");
    }

    fclose(outputfile);

    printf("output success\n");
}

int main(int argc, char *argv[]) {
    int N = atoi(argv[1]);
    printf("----------\n");
    printf("main start, args: %d\n", N);

    struct timeval stv, etv;
    gettimeofday(&stv, NULL);
    double *matrix1 = (double *) malloc(N * N * sizeof(double));
    double *matrix2 = (double *) malloc(N * N * sizeof(double));
    double *matrix3 = (double *) malloc(N * N * sizeof(double));
    gettimeofday(&etv, NULL);
    printf("malloc time\n");
    printf("%ld.%06lu\n", etv.tv_sec - stv.tv_sec, etv.tv_usec - stv.tv_usec);

    measureCreateTime(createMatrix, matrix1, matrix2, matrix3, N);
    measureCalculateTime(calculateMatrix, matrix1, matrix2, matrix3, N);
    outputMatrix(matrix3, N);

    printf("main end\n");
    return 0;
}