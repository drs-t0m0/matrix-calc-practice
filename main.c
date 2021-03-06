#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <omp.h>

void createMatrix(int *matrix, int N) {
#pragma omp parallel for
    for (int i = 0; i < N * N; i++) {
        matrix[i] = i + 1;
    }
}

void calculateMatrix(int *matrix1, int *matrix2, int *matrix3, int N) {
    // ここでmatrix2は転置したとする
    for (int j = 0; j < N; ++j) {
        for (int i = 0; i < N; ++i) {
            int sum = 0;
//            int in = i * N;
            for (int k = 0; k < N; ++k) {
                sum += matrix1[i * N + k + 0] * matrix2[(j + 0) * N + k];
//                sum += matrix1[in + k + 1] * matrix2[(k + 1) * N + j];
//                sum += matrix1[in + k + 2] * matrix2[(k + 2) * N + j];
//                sum += matrix1[in + k + 3] * matrix2[(k + 3) * N + j];
//                sum += matrix1[in + k + 4] * matrix2[(k + 4) * N + j];
//                sum += matrix1[in + k + 5] * matrix2[(k + 5) * N + j];
//                sum += matrix1[in + k + 6] * matrix2[(k + 6) * N + j];
//                sum += matrix1[in + k + 7] * matrix2[(k + 7) * N + j];
            }
            matrix3[i * N + j] = sum;
        }
    }
}

void measureCreateTime(void (*pf)(int *, int), int *matrix1, int *matrix2, int *matrix3, int N) {
    struct timeval stv, etv;
    gettimeofday(&stv, NULL);

    printf("create time\n");
    pf(matrix1, N);
    pf(matrix2, N);
    pf(matrix3, N);

    gettimeofday(&etv, NULL);

    printf("%ld.%06lu\n", etv.tv_sec - stv.tv_sec, etv.tv_usec - stv.tv_usec);
}

void measureCalculateTime(void (*pf)(int *, int *, int *, int), int *matrix1, int *matrix2, int *matrix3, int N) {
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

    measureCreateTime(createMatrix, matrix1, matrix2, matrix3, N);
//    int ans = 0;
//#pragma omp parallel for reduction(+:ans)
//    for (int i = 0; i < N; ++i) {
////        printf("i = %d, thread = %d\n", i, omp_get_thread_num());
////        ans += matrix1[i] * matrix2[i];
//        ans += 1 + 1;
//    }

//    printf("ans = %d\n", ans);
//    printf("threads = %d\n", omp_get_max_threads());

    measureCalculateTime(calculateMatrix, matrix1, matrix2, matrix3, N);

    printf("main end\n");
    return 0;
}