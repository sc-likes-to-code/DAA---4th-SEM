#include <stdio.h>
#include <limits.h>

#define MAX 100

void primMST(int graph[MAX][MAX], int n)
{
    int selected[MAX] = {0};
    int totalCost = 0;

    selected[0] = 1;

    printf("Edges in MST: \n");

    for (int edges = 0; edges < n-1; edges++)
    {
        int min = INT_MAX;
        int x = -1, y = -1;

        for (int i = 0; i < n; i++)
        {
            if (selected[i])
            {
                for (int j = 0; j < n; j++)
                {
                    if (!selected[j] && graph[i][j])
                    {
                        if (graph[i][j] <  min)
                        {
                            min = graph[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }

        if (x != -1 && y != -1)
        {
            printf("%d - %d : %d\n", x, y, graph[x][y]);
            totalCost += graph[x][y];
            selected[y] = 1;
        }
    }

    printf("Total cost of MST: %d\n",totalCost);
}

int main()
{
    int n, graph[MAX][MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (0 if no edge):\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    primMST(graph, n);

    return 0;
}
