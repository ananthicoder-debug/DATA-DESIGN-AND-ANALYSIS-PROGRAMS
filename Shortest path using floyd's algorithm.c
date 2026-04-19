#include <stdio.h>

#define INF 99999

void floydWarshall(int V, int dist[V][V]) {
    int i, j, k;

    // Core Dynamic Programming Logic
    for (k = 0; k < V; k++) {
        for (i = 0; i < V; i++) {
            for (j = 0; j < V; j++) {
                // If vertex k is an intermediate point that shortens the path, update it
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Print the final shortest distance matrix
    printf("\nThe Shortest Distance Matrix:\n");
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

int main() {
    int V, i, j;

    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    int dist[V][V];

    printf("Enter the adjacency matrix (Enter %d for INF):\n", INF);
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            scanf("%d", &dist[i][j]);
        }
    }

    floydWarshall(V, dist);

    return 0;
}
