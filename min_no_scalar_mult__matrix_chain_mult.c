#include <stdio.h>
#include <limits.h>

int MatrixChainMultiplication(int p[], int i , int j)
{
    if (i == j)
        return 0;

    int minOperations = INT_MAX;

    for (int k = i; k < j; k++)
    {
        int count = MatrixChainMultiplication(p, i, k) +
                    MatrixChainMultiplication(p, k + 1, j) +
                    p[i - 1] * p[k] * p[j];

        if (count < minOperations)
            minOperations = count;
    }
    return minOperations;
}

int main()
{
    int p[] = {40, 20, 30, 10, 30}; // dimensions of matrices
    int n = sizeof(p) / sizeof(p[0]);

    int result = MatrixChainMultiplication(p, 1, n - 1);

    printf("Minimum number of multiplications is %d\n", result);

    return 0;
}
