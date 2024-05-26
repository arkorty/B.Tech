#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_N 20

bool is_legal(int board[MAX_N][MAX_N], int row, int col, int N) {
    int i, j;

    // Check if there's a queen in the same column
    for (i = 0; i < row; i++) {
        if (board[i][col])
            return false;
    }

    // Check upper diagonal on left side
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j])
            return false;
    }

    // Check upper diagonal on right side
    for (i = row, j = col; i >= 0 && j < N; i--, j++) {
        if (board[i][j])
            return false;
    }

    return true;
}

void print(int board[MAX_N][MAX_N], int N) {
    // Print the solution
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%c ", board[i][j] ? 'Q' : '.');
        }
        printf("\n");
    }
    printf("\n");
}

bool n_queens(int board[MAX_N][MAX_N], int row, int N) {
    if (row >= N) {
        print(board, N);
        return true;
    }

    bool res = false;
    for (int col = 0; col < N; col++) {
        if (is_legal(board, row, col, N)) {
            board[row][col] = 1;

            // Recur to place rest of the queens
            res = n_queens(board, row + 1, N) || res;

            // If placing queen in board[i][col] doesn't lead to a solution, then remove queen from board[i][col]
            board[row][col] = 0;
        }
    }

    return res;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <N>\n", argv[0]);
        return 1;
    }

    int N = atoi(argv[1]);
    if (N <= 0 || N > MAX_N) {
        printf("N must be a positive integer less than or equal to %d\n", MAX_N);
        return 1;
    }

    int board[MAX_N][MAX_N] = {0};

    if (!n_queens(board, 0, N)) {
        printf("No solution exists for N = %d\n", N);
    }

    return 0;
}
