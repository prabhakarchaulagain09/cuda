#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>  // For timing

using namespace std;

// Function to allocate memory for a matrix
int** allocateMatrix(int matrix_size) {
    int** matrix = new int*[matrix_size];
    for (int i = 0; i < matrix_size; i++) {
        matrix[i] = new int[matrix_size];
    }
    return matrix;
}

// Function to free the allocated memory for a matrix
void freeMatrix(int** matrix, int matrix_size) {
    for (int i = 0; i < matrix_size; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

// Function to generate a random matrix
void gen_matrix(int** m, int matrix_size) {
    for (int i = 0; i < matrix_size; i++) {
        for (int j = 0; j < matrix_size; j++) {
            m[i][j] = rand() % 100;  // Example range: 0-99
        }
    }
}

// Function to perform matrix multiplication
void matrixMultiply(int** A, int** B, int** C, int matrix_size) {
    for (int i = 0; i < matrix_size; i++) {
        for (int j = 0; j < matrix_size; j++) {
            C[i][j] = 0;  // Initialize C[i][j]
            for (int k = 0; k < matrix_size; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// Function to print the matrix
void print_matrix(int** m, int matrix_size) {
    cout << "Matrix:\n";
    for (int i = 0; i < matrix_size; i++) {
        for (int j = 0; j < matrix_size; j++) {
            cout << m[i][j] << " ";
        }
        cout << "\n";
    }
}

int main(int argc, char** argv) {
    if (argc != 4) {
        cout << "Usage: " << argv[0] << " <start_size> <end_size> <interval>" << endl;
        return 0;
    }
    
    // Parse command-line arguments
    int start_size = std::stoi(argv[1]);
    int end_size = std::stoi(argv[2]);
    int interval = std::stoi(argv[3]);

    srand(time(nullptr));
    
    // int matrix_size = 3;

    for (int matrix_size = start_size; matrix_size <= end_size; matrix_size += interval) {
        // Allocate memory for matrices A, B, and C
        int** A = allocateMatrix(matrix_size);
        int** B = allocateMatrix(matrix_size);
        int** C = allocateMatrix(matrix_size);

        // Generate random matrices A and B
        gen_matrix(A, matrix_size);
        gen_matrix(B, matrix_size);

        // Perform matrix multiplication
        auto start = chrono::high_resolution_clock::now();
        matrixMultiply(A, B, C, matrix_size);
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> elapsed_seconds = end - start;

        cout << matrix_size << "\t" << elapsed_seconds.count() << " seconds" << endl;
    }

    // // Print matrices
    // cout << "Matrix A:\n";
    // print_matrix(A, matrix_size);
    // cout << "Matrix B:\n";
    // print_matrix(B, matrix_size);
    // cout << "Matrix C (Result of A * B):\n";
    // print_matrix(C, matrix_size);
    return 0;
}
