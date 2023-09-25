# Matrix Operations

This program performs various operations on matrices. It reads matrices from a file, allows you to perform operations such as addition, subtraction, multiplication, and calculates the count of ones and their corresponding positions. It also calculates the mean of the matrices and the overall mean.

## Getting Started

To use this program, follow the instructions below:

1. Compile the code using a C compiler.
2. Run the executable file.
3. Enter the name of the file containing the matrices.
4. Choose an operation from the menu.
5. View the results and continue with other operations or exit the program.

## Prerequisites

- C compiler

## Instructions

1. Enter the name of the file containing the matrices.
2. Choose an operation from the menu:
   - Press 1 to view the matrices.
   - Press 2 to add the two matrices (A + B).
   - Press 3 to subtract matrix B from matrix A (A - B).
   - Press 4 to multiply matrices A and B (AB).
   - Press 5 to find the number of ones and their corresponding positions.
   - Press 6 to find the mean of matrices A and B and the overall mean.
   - Press 0 to exit the program.
3. Follow the prompts and view the results.
4. Repeat steps 2-3 for other operations or exit the program.

## Functions

- `FindOrder(char* filename)`: Finds the order of the matrix in the input file.
- `SetMatrices(char* filename, int order, int a[], int b[])`: Sets the values of matrices A and B from the input file.
- `PrintMatrices(int order, int* a, int* b)`: Prints the matrices A and B.
- `Addition(int order, int* a, int* b)`: Performs addition of matrices A and B.
- `Subtraction(int order, int* a, int* b)`: Performs subtraction of matrix B from matrix A.
- `Multiplication(int order, int* a, int* b)`: Performs multiplication of matrices A and B.
- `Commands(const char* filename)`: Displays the list of operations available.
- `CountOnes()`: Finds the number of ones and their corresponding positions in a pre-defined matrix.
- `Mean(int order, int* a, int* b)`: Calculates the mean of matrices A and B and the overall mean.

## License

This project is licensed under the [MIT License](LICENSE).
For more info see the LICENSE file.
