#include <stdio.h>

void swapFloat(float *a, float *b) {
    float temp = *a;
    *a = *b;
    *b = temp;
}

void swapInt(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sortByRatio(float ratio[], int weight[], int value[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (ratio[j] < ratio[j+1]) {
                swapFloat(&ratio[j], &ratio[j+1]);
                swapInt(&weight[j], &weight[j+1]);
                swapInt(&value[j], &value[j+1]);
            }
        }
    }
}

int main() {
    int n = 3;
    int weight[] = {10, 20, 30};
    int value[]  = {60, 100, 120};
    int W = 50;

    float ratio[n];
    for (int i = 0; i < n; i++) {
        ratio[i] = (float)value[i] / weight[i];
    }

    sortByRatio(ratio, weight, value, n);

    float totalValue = 0.0;
    for (int i = 0; i < n && W > 0; i++) {
        if (weight[i] <= W) {
            totalValue += value[i];
            W -= weight[i];
        } else {
            totalValue += ratio[i] * W;
            W = 0;
        }
    }

    printf("Maximum value in knapsack: %.2f\n", totalValue);

    return 0;
}
