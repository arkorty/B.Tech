/*
   Program: Matrix Chain Multiplication Optimization
   Description: This program calculates the optimal order of multiplication for a given sequence of matrices using
   dynamic programming. It employs the matrix chain order algorithm to minimize the number of scalar multiplications
   required to compute the product of multiple matrices.

   Functions:
     - matrix_chain_order(int *p, int n, int *m[], int *s[]): Calculates the minimum number of scalar multiplications
   needed to compute the product of multiple matrices and stores the results in matrices m and s.
     - optimal_parenthesis(int *s[], int i, int j): Recursively prints the optimal parenthesized expression of matrix
   multiplication based on the solution matrix s.
     - main(int argc, char *argv[]): Entry point of the program. Initializes the matrices representing the dimensions of
   the matrices to be multiplied, calls matrix_chain_order to calculate the optimal order, and prints the result.

   Input:
     - An array p[] containing the dimensions of the matrices to be multiplied.

   Output:
     - The minimum number of scalar multiplications required.
     - The optimal order of matrix multiplication as a parenthesized expression.

   Approach:
     - The program starts by defining the necessary functions: matrix_chain_order and optimal_parenthesis.
     - The matrix_chain_order function calculates the minimum number of scalar multiplications needed to compute the
   product of multiple matrices and stores the results in matrices m and s.
     - The optimal_parenthesis function recursively prints the optimal parenthesized expression of matrix multiplication
   based on the solution matrix s.
     - In the main function, an array representing the dimensions of the matrices is initialized.
     - The matrix_chain_order function is called to calculate the optimal order of multiplication, and the resulting
   matrices are printed.
     - The optimal parenthesized expression for matrix multiplication is printed based on the solution matrix s.
*/

#include <stdio.h>

#define ROW 7

void matrix_chain_order(int *p, int n, int *m[], int *s[]) {
    int row = n + 1;
    for (int i = 1; i <= n; i++)
        *((int *)m + row * i + i) = 0;

    for (int l = 2; l <= n; l++) {
        for (int i = 1; i <= (n - l + 1); i++) {
            int j = i + l - 1;
            *((int *)m + row * i + j) = -1;
            for (int k = i; k <= (j - 1); k++) {
                int tmp1 = *((int *)m + row * i + k);
                int tmp2 = *((int *)m + row * (k + 1) + j);
                int q = tmp1 + tmp2 + p[i - 1] * p[k] * p[j];

                int old = *((int *)m + row * i + j);
                if (q < old || old == -1) {
                    *((int *)m + row * i + j) = q;
                    *((int *)s + row * i + j) = k;
                }
            }
        }
    }
}

void optimal_parenthesis(int *s[], int i, int j) {
    if (i == j)
        printf("Mat-%d", i);
    else {
        printf("(");
        optimal_parenthesis(s, i, *((int *)s + ROW * i + j));
        optimal_parenthesis(s, *((int *)s + ROW * i + j) + 1, j);
        printf(")");
    }
}

int main(int argc, char *argv[]) {
    if (argc > 1) {
        return 0;
    }
    int n = 6;
    int p[ROW] = {30, 35, 15, 5, 10, 20, 25};
    int m[n + 1][n + 1];
    int s[n + 1][n + 1];

    matrix_chain_order(p, n, (int **)m, (int **)s);
    int i, j;
    for (i = 1; i <= n; i++) {
        for (j = i; j <= n; j++) {
            printf("%d\t", m[i][j]);
        }
        printf("\n");
    }

    optimal_parenthesis((int **)s, 1, 6);
    putchar('\n');

    return 0;
}
