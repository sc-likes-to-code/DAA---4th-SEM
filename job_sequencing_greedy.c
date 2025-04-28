#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Sort jobs by decreasing profit
void sortByProfit(int id[], int deadline[], int profit[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (profit[j] < profit[j+1]) {
                swap(&profit[j], &profit[j+1]);
                swap(&deadline[j], &deadline[j+1]);
                swap(&id[j], &id[j+1]);
            }
        }
    }
}

int min(int a, int b) {
    return (a < b) ? a : b;
}

int main() {
    int n;
    printf("Enter number of jobs: ");
    scanf("%d", &n);

    int id[n], deadline[n], profit[n];

    for (int i = 0; i < n; i++) {
        printf("Enter job id, deadline and profit for job %d: ", i+1);
        scanf("%d%d%d", &id[i], &deadline[i], &profit[i]);
    }

    sortByProfit(id, deadline, profit, n);

    // Find maximum deadline to size the slots
    int maxDeadline = 0;
    for (int i = 0; i < n; i++) {
        if (deadline[i] > maxDeadline)
            maxDeadline = deadline[i];
    }

    int slot[maxDeadline];
    for (int i = 0; i < maxDeadline; i++)
        slot[i] = -1;

    int totalProfit = 0;

    printf("\nScheduled Jobs: ");
    for (int i = 0; i < n; i++) {
        for (int j = min(deadline[i], maxDeadline) - 1; j >= 0; j--) {
            if (slot[j] == -1) {
                slot[j] = id[i];
                totalProfit += profit[i];
                printf("%d ", id[i]);
                break;
            }
        }
    }

    printf("\nTotal Profit: %d\n", totalProfit);

    return 0;
}
