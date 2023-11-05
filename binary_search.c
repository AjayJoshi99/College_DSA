#include <stdio.h>

int binary_search(int *arr, int n, int low, int high)
{

    if (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == n)
        {
            return mid;
        }
        if (arr[mid] > n)
        {
            return binary_search(arr, n, low, mid - 1);
        }
        else
        {
            return binary_search(arr, n, mid + 1, high);
        }
    }
    return -1;
}

void main()
{

    printf("Name : Ajay Joshi\nEnrollment No. : 92201703192\n\n");
    printf("\n.................Binary_search.......................\n\n");
    int arr[] = {12, 14, 18, 24, 26, 35, 37, 41, 42, 53, 55, 68, 62, 79, 90}, num, choice;
    do
    {
        printf("\nEnter 0 for exit\nEnter 1 for searching.");
        printf("\nEnter choice :  ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 0:
            break;
        case 1:
            printf("\nEnter number for searching  :  ");
            scanf("%d", &num);
            int idx = binary_search(arr, num, 0, 14);

            if (idx != -1)
                printf("Given element is present at %d position.\n", idx + 1);
            else
                printf("Element not found!!!!\n");
            break;

        default:
            printf("Invalid choice!!!\n");
        }

    } while (choice != 0);
}