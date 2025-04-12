#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sortJobsByProfit(int id[], int deadline[], int profit[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (profit[j] < profit[j + 1]) {
                swap(&profit[j], &profit[j + 1]);
                swap(&deadline[j], &deadline[j + 1]);
                swap(&id[j], &id[j + 1]);
            }
        }
    }
}

int min(int a, int b) {
    return (a < b) ? a : b;
}

int main() {
    int id[] = {1, 2, 3, 4, 5};           // Job IDs
    int deadline[] = {2, 1, 2, 1, 3};     // Deadlines
    int profit[] = {100, 19, 27, 25, 15}; // Profits
    int n = sizeof(id) / sizeof(id[0]);

    sortJobsByProfit(id, deadline, profit, n);

    int maxDeadline = 0;
    for (int i = 0; i < n; i++) {
        if (deadline[i] > maxDeadline)
            maxDeadline = deadline[i];
    }

    int slot[maxDeadline];
    for (int i = 0; i < maxDeadline; i++)
        slot[i] = -1;

    int totalProfit = 0;

    printf("Scheduled Jobs: ");
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
