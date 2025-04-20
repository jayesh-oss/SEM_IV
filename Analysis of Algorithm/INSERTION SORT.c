#include<math.h>
#include<stdio.h>
void insertionSort(int arr[], int N)
{
    int i,key,j;
    for(i=1;i<N;i++)
    {
        key = arr[i];
        j=i-1;
        while(j>=0 && arr[j]>key)
        {
            arr[j+1] = arr[j];
            j=j-1;
        }
        arr[j+1] = key;
    }
}
void main()
{
    int i;
    int arr[] = {12,11,13,5,6};
    int N = sizeof(arr)/sizeof(arr[0]);
    printf("\nUnsorted array: ");
    for(i=0;i<N;i++) 
    {
        printf("%d",arr[i]);
    }
    printf("\n");
    insertionSort(arr,N);
    printf("\nSorted array: ");
    for(i=0;i<N;i++)
    {
        printf("%d",arr[i]);
    }
    printf("\n");
    getch();
}
    