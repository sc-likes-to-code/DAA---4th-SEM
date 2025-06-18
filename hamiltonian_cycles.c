#include <stdio.h>

#define MAX 10  // Maximum number of vertices

int graph[MAX][MAX];
int path[MAX];
int V; // Number of vertices

// Check if vertex v can be added at position pos in the path
int isSafe(int v, int pos) {
    // Check if this vertex is connected to the previous one
    if (graph[path[pos - 1]][v] == 0)
        return 0;

    // Check if vertex has already been included in the path
    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return 0;

    return 1;
}

// Recursive utility to generate Hamiltonian Cycle
void hamiltonianCycleUtil(int pos) {
    if (pos == V) {
        // If last vertex is connected to the first vertex
        if (graph[path[pos - 1]][path[0]] == 1) {
            for (int i = 0; i < V; i++)
                printf("%d ", path[i]);
            printf("%d\n", path[0]);  // To show cycle
        }
        return;
    }

    // Try different vertices as next candidate
    for (int v = 1; v < V; v++) {
        if (isSafe(v, pos)) {
            path[pos] = v;
            hamiltonianCycleUtil(pos + 1);
            path[pos] = -1;  // Backtrack
        }
    }
}

int main() {
    printf("Enter the number of vertices (max %d): ", MAX);
    scanf("%d", &V);

    if (V > MAX || V < 1) {
        printf("Invalid number of vertices.\n");
        return 0;
    }

    printf("Enter the adjacency matrix (%d x %d):\n", V, V);
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            scanf("%d", &graph[i][j]);

    // Initialize path with -1
    for (int i = 0; i < V; i++)
        path[i] = -1;

    path[0] = 0;  // Start from vertex 0

    printf("Hamiltonian Cycles in the given graph:\n");
    hamiltonianCycleUtil(1);

    return 0;
}
