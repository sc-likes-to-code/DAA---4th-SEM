#include <stdio.h>
#include <limits.h>

int MatrixChainMultiplication(int p[], int i , int j)
{
    if (i==j)
        return 0;
    int minOperations = INT_MAX;

    for (int k=i; k<j; k++)
    {
        int count = MatrixChainMultiplication(p,i,k) + MatrixChainMultiplication(p,k+1,j) + p[i-1] * p[k] * p[j];
        if (count < minOperations)
            minOperations = count;
    }
    return minOperations;
}
int main()
{
    printf("Hello world!\n");
    return 0;
}
