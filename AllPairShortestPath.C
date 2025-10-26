#include <stdio.h>
#define INF 99999

void printSolution(int V, int dist[V][V]) {
    printf("The following matrix shows the shortest distances between every pair of vertices:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            // --- CHANGE 2: Use standard 2D array indexing ---
            if (dist[i][j] == INF)
                printf("%7s", "INF");
            else
                printf("%7d", dist[i][j]);
        }
        printf("\n");
    }
}

void FloydWarshall(int V, int dist[V][V]) {
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF &&
                    dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    printSolution(V, dist);
}

int main() {
    int V;
    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    int dist[V][V]; // VLA (Variable Length Array)

    printf("Enter the adjacency matrix:\n");
    printf("Use 99999 for infinity (no direct edge).\n");

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &dist[i][j]);
        }
    }
    FloydWarshall(V, dist);
    return 0;
}
