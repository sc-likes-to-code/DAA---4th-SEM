#include <stdio.h>
#include <limits.h>

#define MAX 100

int tspGreedy(int graph[MAX][MAX], int n, int start)
{
    int visited[MAX] = {0};
    int cost = 0;
    int current = start;

    visited[current] = 1;
    printf("Path: %d -> ", current);

    for (int count = 0; count < n-1; count++)
    {
        int next = -1;
        int min = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            if (!visited[i] && graph[current][i] && graph[current][i] < min)
            {
                min = graph[current][i];
                next = i;
            }
        }

        if (next == -1)
            return -1;

        visited[next] = 1;
        cost += graph[current][next];
        current = next;

        printf("%d -> ", current);
    }

    cost += graph[current][start];
    printf("%d\n", start);

    return cost;
}

int main()
{
    int graph[MAX][MAX];
    int n, start;

    printf("Enter number of cities: ");
    scanf("%d", &n);

    printf("Enter cost adjacency matrix (0 if no direct path):\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    printf("Enter starting city (0 to %d):", n-1);
    scanf("%d",&start);

    int totalCost = tspGreedy(graph, n, start);
    if (totalCost == -1)
        printf("No complete tour possible.\n");
    else
        printf("Total travel cost: %d\n",totalCost);

    return 0;
}
