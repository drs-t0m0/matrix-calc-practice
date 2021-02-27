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
//            printf("%d * %d + %d = %d\n", i, N, j, sum);
        }
//        printf("\n");
    }
}

void MeasureTime(void (*pf)(int *, int *, int *, int), int *matrix1, int *matrix2, int *matrix3, int N) {
    struct timeval stv, etv;
    gettimeofday(&stv, NULL);
//    printf("%ld %06lu\n", stv.tv_sec, stv.tv_usec);

    pf(matrix1, matrix2, matrix3, N);

    gettimeofday(&etv, NULL);
//    printf("%ld %06lu\n", etv.tv_sec, etv.tv_usec);

    printf("%ld %06lu\n", etv.tv_sec - stv.tv_sec, etv.tv_usec - stv.tv_usec);

//    time_t start_time = gettimeofday(NULL);
//    pf(matrix1, matrix2, matrix3, N);
//    time_t end_time = time(NULL);
//    printf("time:%ld\n", end_time - start_time);
}

int main() {
    int N = 1000;
    int *matrix1 = (int *) malloc(N * N * sizeof(int));
    int *matrix2 = (int *) malloc(N * N * sizeof(int));
    int *matrix3 = (int *) malloc(N * N * sizeof(int));
//    int matrix1[N * N];
//    int matrix2[N * N];
//    int matrix3[N * N];

    CreateMatrix(matrix1, N);
    CreateMatrix(matrix2, N);
    CreateMatrix(matrix3, N);

//    CalculateMatrix(matrix1, matrix2, matrix3, N);

//    for (int i = 0; i < N * N; ++i) {
//        printf("%d\n", matrix3[i]);
//    }

    MeasureTime(CalculateMatrix, matrix1, matrix2, matrix3, N);

    return 0;
}