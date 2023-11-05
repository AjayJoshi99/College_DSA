#include <stdio.h>

int linear_search(int *arr, int n, int size)
{
    for(int i =0; i<size; i++){
        if(arr[i]==n){
            return i;
        }
    }

    return -1;
}

void main()
{

    printf("Name : Ajay Joshi\nEnrollment No. : 92201703192\n\n");
    printf("\n.................Linear_search.......................\n\n");
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
            int idx = linear_search(arr, num, 15);

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