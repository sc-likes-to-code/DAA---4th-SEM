#include <stdio.h>

void findMinMax(int arr[], int left, int right, int *min, int *max)
{
    int leftMin, leftMax, rightMin, rightMax;

    if (left == right)
    {
        *min = *max = arr[left];
        return;
    }

    if (right == left + 1)
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
        return;
    }

    int mid = left + (right - left) / 2;

    findMinMax(arr, left, mid, &leftMin, &leftMax);
    findMinMax(arr, mid + 1, right, &rightMin, &rightMax);

    *min = (leftMin < rightMin) ? leftMin : rightMin;
    *max = (leftMax > rightMax) ? leftMax : rightMax;
}

int main()
{
    int arr[] = {3, 5, 1, 8, 2, 9, 0, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int min, max;

    findMinMax(arr, 0, n - 1, &min, &max);

    printf("Minimum: %d\n", min);
    printf("Maximum: %d\n", max);

    return 0;
}
