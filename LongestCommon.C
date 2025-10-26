#include <stdio.h>
#include <string.h>

void print_matrix(int m, int n, int matrix[m + 1][n + 1]) {
    int i, j;
    printf("Solution Matrix (C):\n");
    for (i = 0; i <= m; i++) {
        for (j = 0; j <= n; j++) {
            printf("%d  ", matrix[i][j]);
        }
        printf("\n");
    }
}

void longest_common_subsequence(char x[], char y[]) {
    int m, n, i, j, index;
    m = strlen(x);
    n = strlen(y);
    int c[m + 1][n + 1];
    char b[m + 1][n + 1];
    for (i = 0; i <= m; i++) {
        c[i][0] = 0;
    }
    for (j = 0; j <= n; j++) {
        c[0][j] = 0;
    }
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

    print_matrix(m, n, c);

    index = c[m][n];
    printf("\nLength of LCS: %d\n", index);

    char lcs[index + 1];
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
}

int main() {
    char x[] = "ABCBDAB";
    char y[] = "BDCABA";
    longest_common_subsequence(x, y);
    return 0;
}
