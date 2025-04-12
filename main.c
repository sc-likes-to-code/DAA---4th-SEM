#include <stdio.h>

void findMinMax(int arr[], int left, inr right, int *min, int *max)
{
    int leftMin, int leftMax, rightMin, rightMax;

    if (left==right)
    {
        *min=*max=arr[left];
        return;
    }
    if (right == left+1)
    {
        if (arr[left] < arr[right])
        {
            *min = arr[left];
            *max = arr[right];
        }
        else
        {
            *min = arr[right];
            *max = arr[left];
        }
    }

    int mid = left + (right - left)/2;

    findMinMax(arr, left, mid, &leftMin, &leftMax);
    findMinMax(arr, mid+1, right, &rightMin, &rightMax);

    *min = (leftMin<rightMin)? leftMin : rightMin;
    *max = (leftMax>rightMax)? leftMax : rightMax;
}

int main()
{
    printf("Hello world!\n");
    return 0;
}
