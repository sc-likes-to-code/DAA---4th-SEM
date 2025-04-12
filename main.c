#include <stdio.h>

int binarySearch(int arr[], int left, int right, int key)
{
    if (left > right)
        return -1;
    int mid = left+ (right-left)/2;
    if (arr[mid] == key)
        return mid;
    else if(arr[mid] > key)
        return binarySearch(arr,left,mid-1,key);
    else
        return binarySearch(arr,mid+1,right,key);
}


int main()
{
    int i,n,key;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    int a[n];
    printf("Enter the elements in sorted order:\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("Enter element to be searched: ");
    scanf("%d",&key);
    int result = binarySearch(a,0,n-1,key);
    if (result!=-1)
        printf("Element found at index: %d",result);
    else
        printf("Element not found!!");
    return 0;
}
