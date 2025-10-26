#include <stdio.h>
#include <stdlib.h> 
#include <conio.h>

void printSolution(int board[], int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (board[i] == j) {
                printf(" Q ");
            } else {
                printf(" _ ");
            }
        }
        printf("\n");
    }
}

int isSafe(int board[], int row, int col) {
    int i; /* Declare variable at top */
    for (i = 0; i < row; i++) {
        if (board[i] == col || abs(board[i] - col) == abs(i - row)) {
            return 0;
        }
    }
    return 1; 
}

int solveNQueens(int board[], int row, int n) {
    int col;
    if (row >= n) {
        return 1; 
    }
    for (col = 0; col < n; col++) {
        if (isSafe(board, row, col)) {
            board[row] = col;
            if (solveNQueens(board, row + 1, n)) {
                return 1; /* true */
            }
        }
    }
    return 0;
}

int main() {
    int n;
    int* board; 
    clrscr(); 
    printf("Enter the size of the chessboard (N): ");
    scanf("%d", &n);
    board = (int*)malloc(n * sizeof(int));
    if (board == NULL) {
        printf("Error: Memory allocation failed.\n");
        return 1;
    }
    
    if (solveNQueens(board, 0, n)) {
        printf("\nSolution for N = %d:\n", n);
        printSolution(board, n);
    } else {
        printf("\nSolution does not exist for N = %d.\n", n);
    }

    free(board);
    
    printf("\nPress any key to exit...");
    getch();

    return 0;
}
