#include<stdio.h>

void swapInt(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swapDouble(double *a, double *b)
{
    double temp = *a;
    *a = *b;
    *b = temp;
}

void sortItems(int weights[], int profits[], double ratio[], int n)
{
    for(int i = 0; i < n-1; i++)
    {
        for(int j = 0; j < n-i-1; j++)
        {
            if (ratio[j+1] > ratio[j])
            {
                swapDouble(&ratio[j],&ratio[j+1]);
                swapInt(&weights[j], &weights[j+1]);
                swapInt(&profits[j], &profits[j+1]);
            }
        }
    }
}

double fractionalKnapsack(int weights[], int profits[], double ratio[], int n, int capacity)
{
    sortItems(weights, profits, ratio, n);
    double totalProfit = 0.0;

    for (int i = 0; i < n && capacity > 0; i++)
    {
        if (weights[i] <= capacity)
        {
            totalProfit += profits[i];
            capacity -= weights[i];
        }
        else
        {
            totalProfit += profits[i] * ((double)capacity/ weights[i]);
            capacity = 0;
        }
    }

    return totalProfit;
}

int main()
{
    int n;
    double capacity;

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter capacity of knapsack: ");
    scanf("%lf", &capacity);

    int weights[n], profits[n];
    double ratio[n];

    for (int i = 0; i < n; i++)
    {
        printf("Enter weight and profit for item %d: ", i+1);
        scanf("%d%d", &weights[i], &profits[i]);
        ratio[i] = (double) profits[i]/ weights[i];
    }

    double maxProfit = fractionalKnapsack(weights, profits, ratio, n, capacity);

    printf("\nMaximum profit = %.2lf\n", maxProfit);

    return 0;
}
