//{{1, 2},
//{3, 4}}
//----------
//7    10
//15    22
//----------
//{1, 2, 3, 4}
//a1 = m[0] * m[0] + m[1] * m[2]
//a2 = m[0] * m[1] + m[1] * m[3]
//a3 = m[2] * m[0] + m[3] * m[2]
//a4 = m[2] * m[1] + m[3] * m[3]

//{{1, 2, 3},
//{4, 5, 6},
//{7, 8, 9}}
//----------
//{1, 2, 3, 4, 5, 6, 7, 8, 9}
//a1 = m[0] * m[0] + m[1] * m[3] + m[2] * m[6]
//a2 = m[0] * m[1] + m[1] * m[4] + m[2] * m[7]
//a3 = m[0] * m[2] + m[1] * m[5] + m[2] * m[8]
//a4 = m[3] * m[0] + m[4] * m[3] + m[5] * m[6]
//a5 = m[3] * m[1] + m[4] * m[4] + m[5] * m[7]
//a6 = m[3] * m[2] + m[4] * m[5] + m[5] * m[8]
//a7 = m[6] * m[0] + m[7] * m[3] + m[8] * m[6]
//a8 = m[6] * m[1] + m[7] * m[4] + m[8] * m[7]
//a9 = m[6] * m[2] + m[7] * m[5] + m[8] * m[8]

//30    36    42
//66    81    96
//102   126   150

//{{1, 2, 3, 4},
//{5, 6, 7, 8},
//{9, 10, 11, 12},
//{13, 14, 15, 16}}
//----------
//90   100   110   120
//202   228   254   280
//314   356   398   440
//426   484   542   600

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