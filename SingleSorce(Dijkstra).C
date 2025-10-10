#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <limits.h>

// Defines for the maximum number of vertices
#define row 6
#define col 6

// Function to find the shortest path from a single source vertex 'v'
void ShortestPath(int v, int matrix[row][col], int n)
{
    // S[]: Set of vertices included in the shortest path tree (1 if included, 0 otherwise)
    // dist[]: Array to store the shortest distance from source 'v' to all other vertices
    int S[row], dist[row];
    int i, j, k, u;

    // 1. Initialization
    for (i = 0; i < n; i++)
    {
        // Initially, no vertex is in the shortest path set S
        S[i] = 0;
        // Initialize distances directly from the source 'v'
        dist[i] = matrix[v][i];
    }

    // Include source vertex 'v' in the shortest path set S
    S[v] = 1;
    // Distance from source to itself is 0
    dist[v] = 0;

    // 2. Main loop: Find shortest path for all vertices
    // The loop runs n-1 times since the source is already finalized
    for (k = 0; k < n - 1; k++)
    {
        // Find the vertex 'u' with the minimum distance among those not yet included in S
        int min_dist = INT_MAX;
        u = -1; // 'u' will store the index of the vertex to be included next

        for (i = 0; i < n; i++)
        {
            if (S[i] == 0 && dist[i] < min_dist)
            {
                min_dist = dist[i];
                u = i;
            }
        }

        // If 'u' is -1, it means all remaining vertices are unreachable (distance INT_MAX)
        if (u == -1)
            break;

        // Add the newly found minimum distance vertex 'u' to the shortest path set S
        S[u] = 1;

        // 3. Update distance values of the adjacent vertices of 'u'
        for (i = 0; i < n; i++)
        {
            // Update dist[i] only if:
            // a) vertex 'i' is not in S
            // b) there is an edge from 'u' to 'i' (matrix[u][i] != 0)
            // c) the path through 'u' is shorter than the current distance to 'i'
            if (S[i] == 0 && matrix[u][i] != 0 && dist[u] != INT_MAX && dist[u] + matrix[u][i] < dist[i])
            {
                dist[i] = dist[u] + matrix[u][i];
            }
        }
    }

    // Print the results
    printf("\nShortest path from source %d:\n", v);
    for (i = 0; i < n; i++)
    {
        printf("Distance to vertex %d is: %d\n", i, dist[i]);
    }
}

// Main function to get input and call the algorithm
void main()
{
    int matrix[row][col], i, j, v;
    int n = row;
    
    clrscr(); 

    printf("Enter matrix elements (use a large number like 9999 for no direct path):\n");
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            printf("Enter element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("\nEnter Source Vertex (0 to %d): ", n - 1);
    scanf("%d", &v);

    ShortestPath(v, matrix, n);
    getch();
}