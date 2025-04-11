#include <stdio.h>

#define MAX 100

int parent[MAX];

int find(int i)
{
    while (parent[i] != i)
        i = parent[i];
    return i;
}

void unionSet(int i, int j)
{
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}

int main()
{
    int u[MAX], v[MAX], w[MAX];
    int n, e;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter edges (u v weight):\n");
    for (int i = 0; i < e; i++)
        scanf("%d %d %d", &u[i], &v[i], &w[i]);

    for (int i = 0; i < n; i++)
        parent[i] = i;

    for (int i = 0; i < e-1; i++)
    {
        for (int j = 0; j < e-i-1; j++)
        {
            if (w[j] > w[j+1])
            {
                int temp = w[j];
                w[j] = w[j+1];
                w[j+1] = temp;

                int t = u[j];
                u[j] = u[j+1];
                u[j+1] = t;

                t = v[j];
                v[j] = v[j+1];
                v[j+1] = t;
            }
        }
    }

    int totalCost = 0;
    int edgeCount = 0;

    printf("\nEdges in the MST:\n");
    for (int i = 0; i < e && edgeCount < n-1; i++)
    {
        int a = find(u[i]);
        int b = find(v[i]);

        if (a != b)
        {
            printf("%d - %d : %d\n", u[i], v[i], w[i]);
            totalCost += w[i];
            unionSet(a,b);
            edgeCount++;
        }
    }

    printf("Total cost of MST = %d\n", totalCost);

    return 0;
}
