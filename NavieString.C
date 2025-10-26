#include <stdio.h>
#include <string.h>

#define MAX_SIZE 1000

void naiveStringMatch(const char text[], const char pattern[])
{
    int n = strlen(text);
    int m = strlen(pattern);
    int i;
    int j;
    for (i = 0; i <= n - m; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (text[i + j] != pattern[j])
            {
                break;
            }
        }
        if (j == m)
        {
            printf("Pattern found at index %d\\n", i);
        }
    }
}

int main()
{
    char text[MAX_SIZE];
    char pattern[MAX_SIZE];
    printf("Enter the text: ");
    fgets(text, sizeof(text), stdin);
    printf("Enter the pattern: ");
    fgets(pattern, sizeof(pattern), stdin);

    text[strcspn(text, "\n")] = '\0';
    pattern[strcspn(pattern, "\n")] = '\0';

    naiveStringMatch(text, pattern);
    return 0;

}


