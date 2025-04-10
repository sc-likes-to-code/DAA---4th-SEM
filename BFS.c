#include <stdio.h>
#define MAX 100

int queue[MAX], front = -1, rear = -1;

void enqueue(int vertex)
{
    if (rear == MAX-1)
        return;
    if (front == -1) front = 0;
    queue[++rear] = vertex;
}

int dequeue()
{
    if (front == -1 || front > rear)
        return -1;
    return queue[front++];
}

int isEmpty()
{
    return front == -1 || front > rear;
}

void bfs(int graph[MAX][MAX], int visited[MAX], int start, int n)
{
    enqueue(start);
    visited[start] = 1;

    while (!isEmpty())
    {
        int current = dequeue();
        printf("%d ",current);

        for (int i = 0; i < n; i++)
        {
            if (graph[current][i] && !visited[i])
            {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

int main()
{
    int n, start;
    int graph[MAX][MAX], visited[MAX] = {0};

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("BFS traversal: ");
    bfs(graph, visited, start, n);

    return 0;
}
