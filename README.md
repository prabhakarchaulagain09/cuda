# Matrix Multiplication Benchmark
This project provides a simple program to benchmark matrix multiplication for varying matrix sizes. It dynamically generates matrices with random values, multiplies them, and measures the time taken for each multiplication, allowing the user to observe how execution time scales with matrix size.
Here we only consider square matrices.  

## Compilation  
```bash
g++ matrix.cpp  -o matrix_benchmark 
```
## Usage
To run the program, use the following command-line arguments:

```
./matrix_benchmark <start_size> <end_size> <interval>
```

Where:

- `<start_size>`: The starting size of the square matrices.
- `<end_size>`: The ending size of the square matrices.
- `<interval>`: The interval between the matrix sizes.

For example, to test matrix multiplication for sizes 10, 20, and 30, you would run:

```
./matrix_multiplication 100 3000 200
```

This will print the time taken to perform the matrix multiplication for each matrix size.

## How it Works

The program consists of the following functions:

1. `allocateMatrix(int matrix_size)`: Allocates memory for a square matrix of the given size.
2. `freeMatrix(int** matrix, int matrix_size)`: Frees the memory allocated for a matrix.
3. `gen_matrix(int** m, int matrix_size)`: Generates a random square matrix of the given size.
4. `matrixMultiply(int** A, int** B, int** C, int matrix_size)`: Performs matrix multiplication on the input matrices A and B, storing the result in C.
5. `print_matrix(int** m, int matrix_size)`: Prints the contents of a square matrix.

The `main()` function coordinates the execution of the program:

1. It parses the command-line arguments to get the starting size, ending size, and interval for the matrix sizes.
2. It then iterates through the matrix sizes, performing the following steps for each size:
   - Allocates memory for the input matrices A and B, and the result matrix C.
   - Generates random values for A and B.
   - Calls `matrixMultiply()` to perform the matrix multiplication.
   - Measures the time taken for the multiplication and prints the matrix size and the elapsed time.
3. Finally, it frees the memory allocated for the matrices.

The `print_matrix()` function is commented out in the main function, as it is only useful for small matrices for debugging purposes.

## Dependencies

This program requires the following C++ standard library headers:

- `<iostream>`: For input/output operations.
- `<cstdlib>`: For random number generation.
- `<ctime>`: For seeding the random number generator.
- `<chrono>`: For measuring the time taken to perform the matrix multiplication.

