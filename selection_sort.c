#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void selection_short(int *arr, int n)
{
    int min_ind,i,j;
    for ( i = 0; i < n - 1; i++)
    {
        min_ind = i;
        for ( j = i; j < n; j++)
        {
            if (arr[j] < arr[min_ind])
                min_ind = j;
        }

        if (min_ind != i)
        {
            int temp = arr[i];
            arr[i] = arr[min_ind];
            arr[min_ind] = temp;
        }
    }
}

void main()
{

    int size;
    printf("Enter size of array  : ");
    scanf("%d", &size);

    int *arr = (int *)malloc(size * sizeof(int));

    printf("Enter element of array :\n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    selection_short(arr, size);

    printf("\nSorted array is : \n");
    for (int i = 0; i < size; i++)
    {
        printf("%d  ", arr[i]);
    }
}