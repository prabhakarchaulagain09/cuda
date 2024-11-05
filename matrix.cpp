#include <stdio.h>
#define N 3  // Define matrix size

void matrixMultiply(int A[N][N], int B[N][N], int C[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = 0;  // Initialize C[i][j]
            for (int k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];  // Summing the products
            }
        }
    }
}

int main() {
    int A[N][N] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int B[N][N] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
    int C[N][N] = {0};  // Result matrix

    matrixMultiply(A, B, C);

    // Print result
    printf("Resulting Matrix C:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}

