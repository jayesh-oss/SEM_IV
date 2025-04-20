#include<stdio.h>
void merge(int arr[], int left, int mid, int right) 
{
    int i=left, j=mid+1, k=0;
    int temp[right-left+1];
    while (i<=mid && j<=right) 
    {
        if (arr[i] <= arr[j]) 
        {
            temp[k++] = arr[i++];
        } 
        else
        {
            temp[k++] = arr[j++];
        }
    }
    while (i <= mid) 
    {
        temp[k++] = arr[i++];
    }
    while (j <= right) 
    {
        temp[k++] = arr[j++];
    }
    for (i = left, k = 0; i <= right; i++, k++) 
    {
        arr[i] = temp[k];
    }
}
void mergeSort(int arr[], int left, int right) 
{
    if (left < right) 
    {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}
void printArray(int arr[], int size) 
{
    for (int i = 0; i < size; i++) 
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main() 
{
    int n;
    printf("\n Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("\n Enter %d elements: ", n);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }
    printf("\n Original array:\n");
    printArray(arr, n);
    mergeSort(arr, 0, n - 1);
    printf("\n Sorted array:\n");
    printArray(arr, n);
    return 0;
}