#include <stdio.h>

#define INF 99999

void printSolution(int dist[], int V) {
    printf("The following matrix shows the shortest distances between every pair of vertices:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i * V + j] == INF)
                printf("%7s", "INF");
            else
                printf("%7d", dist[i * V + j]);
        }
        printf("\n");
    }
}

void FloydWarshall(int dist[], int V) {
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i * V + k] != INF && dist[k * V + j] != INF &&
                    dist[i * V + k] + dist[k * V + j] < dist[i * V + j]) {
                    dist[i * V + j] = dist[i * V + k] + dist[k * V + j];
                }
            }
        }
    }
    printSolution(dist, V);
}

int main() {
    int V;
    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    int dist[V][V];

    printf("Enter the adjacency matrix:\n");
    printf("Use 99999 for infinity (no direct edge).\n");

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &dist[i][j]);
        }
    }
    
    // Pass 2D array as 1D array to function for compatibility
    FloydWarshall(&dist[0][0], V);

    return 0;
}