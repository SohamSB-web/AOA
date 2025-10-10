#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Function to print the solution matrix
void printSolution(int board[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i] == j) {
                printf(" Q ");
            } else {
                printf(" _ ");
            }
        }
        printf("\n");
    }
}

// Function to check if a queen can be placed at board[row][col]
bool isSafe(int board[], int row, int col) {
    for (int i = 0; i < row; i++) {
        // Check if there is a queen in the same column or on a diagonal
        if (board[i] == col || abs(board[i] - col) == abs(i - row)) {
            return false;
        }
    }
    return true;
}

// Backtracking function to solve the N-Queen problem
bool solveNQueens(int board[], int row, int n) {
    // Base case: If all queens are placed, return true
    if (row >= n) {
        return true;
    }

    // Consider this row and try placing this queen in all columns one by one
    for (int col = 0; col < n; col++) {
        // Check if the queen can be placed at board[row][col]
        if (isSafe(board, row, col)) {
            // Place the queen
            board[row] = col;

            // Recur to place the rest of the queens
            if (solveNQueens(board, row + 1, n)) {
                return true;
            }

            // If placing queen at board[row][col] doesn't lead to a solution, then backtrack
            // No need to explicitly remove, the next iteration will overwrite
        }
    }
    // If queen cannot be placed in any column in this row, then return false
    return false;
}

int main() {
    int n;
    printf("Enter the size of the chessboard (N): ");
    scanf("%d", &n);

    int board[n];
    
    if (solveNQueens(board, 0, n)) {
        printf("\nSolution for N = %d:\n", n);
        printSolution(board, n);
    } else {
        printf("\nSolution does not exist for N = %d.\n", n);
    }

    return 0;
}