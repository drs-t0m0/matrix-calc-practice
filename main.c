// 行列を作るfor文を書く
// 乱数で初期化


#include <stdio.h>

// 関数作成create matrix
void createMatrix(int * matrix, int N) {
    printf("%p\n", matrix);
    for (int i = 0; i < N * N; i++)
    {
        printf("%p\n", &matrix[i]);
        matrix[i] = i;
    }
}

int main() {
    int N = 3;
    int matrix1[N * N];

    printf("%p\n", matrix1);

    createMatrix(matrix1, N);
    for (int i = 0; i < N * N; i++)
    {
        printf("%d\n", matrix1[i]);
    }
    

    // int matrix2[N][N] = {{1, 2, 3},
    //                      {4, 5, 6},
    //                      {7, 8, 9}};

    // int result[N][N];
    // for (int i = 0; i < N; ++i) {
    //     for (int j = 0; j < N; ++j) {
    //         result[i][j] = 0;
    //         for (int k = 0; k < N; ++k) {
    //             result[i][j] += matrix1[i][k] * matrix2[k][j];
    //         }
    //         printf("%5d ", result[i][j]);
    //     }
    //     printf("\n");
    // }
    
    return 0;
}