#include <stdio.h>
#include<conio.h>
void main()
{
    int arr[50], n, i, min, max;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter array elements-\n");
    for(i = 0; i < n; i++)
    scanf("%d", &arr[i]);
    min = arr[0];
    max = arr[0];
    for (i = 1; i < n; i++)
    {
        if (arr[i] < min)
        min = arr[i];
        if (arr[i] > max)
        max = arr[i];
    }
    printf("\n Minimum number in the array is: %d\n", min);
    printf("\n Maximum number in the array is: %d", max);
    getch();
}