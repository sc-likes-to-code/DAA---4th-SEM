#include <stdio.h>
#define MAX 100

void dfs(int graph[MAX][MAX], int visited[MAX], int vertex, int n)
{
    visited[vertex] = 1;
    printf("%d ", vertex);

    for (int i = 0; i < n; i++)
        if (graph[vertex][i] && !visited[i])
            dfs(graph, visited, i, n);
}

int main()
{
    int graph[MAX][MAX], visited[MAX] = {0};
    int n, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("DFS traversal: ");
    dfs(graph, visited, start, n);

    return 0;
}
