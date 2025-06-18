#include <stdio.h>

#define MAX 20
#define MAX_COLOR_NAME 20

int graph[MAX][MAX];
int color[MAX];
char colorNames[MAX][MAX_COLOR_NAME];
int V, m;
int solutionCount = 0;

// Function to check if current color assignment is safe
int isSafe(int v, int c) {
    for (int i = 0; i < V; i++) {
        if (graph[v][i] && color[i] == c)
            return 0;
    }
    return 1;
}

// Function to print one solution
void printSolution() {
    solutionCount++;
    printf("\nSolution %d:\n", solutionCount);
    for (int i = 0; i < V; i++)
        printf("Vertex %d ---> %s\n", i, colorNames[color[i] - 1]);
}

// Recursive function to find all colorings
void graphColoring(int v) {
    if (v == V) {
        printSolution();
        return;
    }

    for (int c = 1; c <= m; c++) {
        if (isSafe(v, c)) {
            color[v] = c;
            graphColoring(v + 1);
            color[v] = 0; // backtrack
        }
    }
}

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    printf("Enter the number of colors: ");
    scanf("%d", &m);

    printf("Enter the color names:\n");
    for (int i = 0; i < m; i++) {
        printf("Color %d: ", i + 1);
        scanf("%s", colorNames[i]);
    }

    printf("\nEnter the adjacency matrix (%d x %d):\n", V, V);
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            scanf("%d", &graph[i][j]);

    for (int i = 0; i < V; i++)
        color[i] = 0;

    printf("\nAll valid colorings:\n");
    graphColoring(0);

    if (solutionCount == 0)
        printf("\nNo valid colorings found.\n");

    return 0;
}
