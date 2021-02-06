#include <stdio.h>
#include <time.h>

void CreateMatrix(int *matrix, int N) {
    for (int i = 0; i < N * N; i++) {
        matrix[i] = i + 1;
    }
}

void CalculateMatrix(int *matrix1, int *matrix2, int N) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            int sum = 0;
            for (int k = 0; k < N; ++k) {
                sum += matrix1[i * N + k] * matrix2[k * N + j];
            }
            printf("%d ", sum);
        }
        printf("\n");
    }
}

void MeasureTime(void (*pf)(int*, int*, int), int *matrix1, int *matrix2, int N) {
    time_t start_time = time(NULL);
    pf(matrix1, matrix2, N);
    time_t end_time = time(NULL);
    printf("time:%ld\n", end_time - start_time);
}

int main() {
    int N = 400;
    int matrix1[N * N];
    int matrix2[N * N];

    CreateMatrix(matrix1, N);
    CreateMatrix(matrix2, N);

    MeasureTime(CalculateMatrix, matrix1, matrix2, N);

    return 0;
}