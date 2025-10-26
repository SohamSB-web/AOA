#include <stdio.h>
#define INF 99999
#define MAX_V 20 

void printSolution(int V, int dist[MAX_V][MAX_V]) {
    int i, j;
    printf("The following matrix shows the shortest distances between every pair of vertices:\n");
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                printf("%7s", "INF");
            else
                printf("%7d", dist[i][j]);
        }
        printf("\n");
    }
}

void FloydWarshall(int V, int dist[MAX_V][MAX_V]) {
    int i, j, k; 
    for (k = 0; k < V; k++) {
        for (i = 0; i < V; i++) {
            for (j = 0; j < V; j++) {
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
    int i, j;

    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    int dist[MAX_V][MAX_V];

    printf("Enter the adjacency matrix:\n");
    printf("Use 99999 for infinity (no direct edge).\n");

    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            scanf("%d", &dist[i][j]);
        }
    }
    FloydWarshall(V, dist);
    return 0;
}
