#include<stdio.h>
#include<limits.h>

#define MAX 100
#define INF 99999

int graph[MAX][MAX];

void printSolution(int dist[], int V, int src) {
    printf("\nShortest distances from source vertex %d:\n", src);
    for (int i = 0; i < V; i++) {
        if (dist[i] == INF) {
            printf("V%d -> V%d : Unreachable\n", src, i);
        } else {
            printf("V%d -> V%d : %d\n", src, i, dist[i]);
        }
    }
}

void bellmanFord(int dist[], int V, int src) {
    // Relax all edges (V-1) times
    for (int i = 0; i < V - 1; i++) {
        for (int u = 0; u < V; u++) {
            for (int v = 0; v < V; v++) {
                if (dist[u] != INF && graph[u][v] != 0 && dist[u] + graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + graph[u][v];
                }
            }
        }
    }

    // Check for negative-weight cycles
    for (int u = 0; u < V; u++) {
        for (int v = 0; v < V; v++) {
            if (dist[u] != INF && graph[u][v] != 0 && dist[u] + graph[u][v] < dist[v]) {
                printf("\nThis graph contains a negative-weight cycle.\n");
                return; // No need to continue if negative cycle is detected
            }
        }
    }

    // Print the final shortest distances
    printSolution(dist, V, src);
}

int main() {
    int V, src;
    printf("\nEnter the number of vertices: ");
    scanf("%d", &V);

    int dist[V];

    printf("\nEnter the adjacency matrix of the graph:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("\nEnter the source vertex: ");
    scanf("%d", &src);

    // Initialize distances
    for (int i = 0; i < V; i++) {
        dist[i] = INF;
    }
    dist[src] = 0;

    // Run Bellman-Ford algorithm
    bellmanFord(dist, V, src);

    return 0;
}
