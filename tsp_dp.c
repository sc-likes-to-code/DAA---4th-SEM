#include<stdio.h>
#include<limits.h>

#define MAX 10
#define INF 99999

int graph[MAX][MAX]; // Distance matrix
int dp[MAX][MAX]; // DP table to store minimum distances

// Solve TSP using DP (no bitmasking)
void tsp(int n) {
    // Loop through all path lengths from 2 to n (all cities visited)
    for (int len = 2; len <= n; len++) { // path length
        for (int i = 0; i <= n - len; i++) { // starting city
            int j = i + len - 1; // destination city for this path length
            dp[i][j] = INF; // initialize with infinity (large value)

            // Try all possible cities as intermediate points in the path
            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k+1][j] + graph[i][k+1]; // cost of path through k
                if (cost < dp[i][j]) {
                    dp[i][j] = cost; // update with minimum cost
                }
            }
        }
    }
}

int main() {
    int n;
    printf("\nEnter the number of cities: ");
    scanf("%d", &n);

    printf("\nEnter the distance matrix (0 if no direct path):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // Initialize the dp table
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                dp[i][j] = 0; // no cost to stay at the same city
            } else if (graph[i][j] != 0) {
                dp[i][j] = graph[i][j]; // direct distance between cities
            } else {
                dp[i][j] = INF; // no direct path
            }
        }
    }

    // Call the TSP solver
    tsp(n);

    printf("\nThe minimum cost to visit all cities is: %d\n", dp[0][n-1]);

    return 0;
}
