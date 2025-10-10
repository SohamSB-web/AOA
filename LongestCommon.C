#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to print the solution matrix
void print_matrix(int** matrix, int m, int n) {
    int i, j;
    printf("Solution Matrix (C):\n");
    for (i = 0; i <= m; i++) {
	for (j = 0; j <= n; j++) {
	    printf("%d  ", matrix[i][j]);
	}
	printf("\n");
    }
}

// Function to find the longest common subsequence
void longest_common_subsequence(char* x, char* y) {
    // Declare all variables at the beginning of the function
    int m, n, i, j, index;
    int** c;
    char** b;
    char* lcs;

    // Get the lengths of the strings
    m = strlen(x);
    n = strlen(y);

    // Create and initialize tables
    c = (int**)malloc((m + 1) * sizeof(int*));
    for (i = 0; i <= m; i++) {
	c[i] = (int*)malloc((n + 1) * sizeof(int));
    }

    b = (char**)malloc((m + 1) * sizeof(char*));
    for (i = 0; i <= m; i++) {
	b[i] = (char*)malloc((n + 1) * sizeof(char));
    }

    // Initialize the first row and column to 0
    for (i = 0; i <= m; i++) {
	c[i][0] = 0;
    }
    for (j = 0; j <= n; j++) {
	c[0][j] = 0;
    }

    // Fill the tables
    for (i = 1; i <= m; i++) {
	for (j = 1; j <= n; j++) {
	    if (x[i - 1] == y[j - 1]) {
		c[i][j] = c[i - 1][j - 1] + 1;
		b[i][j] = '\\';
	    } else if (c[i - 1][j] >= c[i][j - 1]) {
		c[i][j] = c[i - 1][j];
		b[i][j] = '^';
	    } else {
		c[i][j] = c[i][j - 1];
		b[i][j] = '<';
	    }
	}
    }

    // Print the solution matrix
    print_matrix(c, m, n);

    // Print the length of the LCS
    printf("\nLength of LCS: %d\n", c[m][n]);

    // Allocate memory for the LCS string and reconstruct it
    lcs = (char*)malloc((c[m][n] + 1) * sizeof(char));
    index = c[m][n];
    lcs[index] = '\0';

    i = m; j = n;
    while (i > 0 && j > 0) {
	if (b[i][j] == '\\') {
	    lcs[index - 1] = x[i - 1];
	    index--;
	    i--;
	    j--;
	} else if (b[i][j] == '^') {
	    i--;
	} else {
	    j--;
	}
    }
    printf("LCS: %s\n", lcs);

    // Free the allocated memory
    for (i = 0; i <= m; i++) {
	free(c[i]);
	free(b[i]);
    }
    free(c);
    free(b);
    free(lcs);
}

int main() {
    char x[] = "ABCBDAB";
    char y[] = "BDCABA";
    longest_common_subsequence(x, y);
    return 0;
}