#include <stdio.h>
#include <stdlib.h>


int partition( int *arr,int low, int high){
    int i, j,pivot;
    pivot = arr[low];
    i = low-1;
    j = high+1;

    while(i<j){
        do{
            i++;
        }while(arr[i] < pivot && i<=high);

        do{
            j--;
        }while(arr[j]>pivot);

        if(i<j){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[low];
    arr[low] =arr[j];
    arr[j] = temp;

    return j;
}

 void quick_sort(int *arr, int low, int high){
    int j;
    if(low<high){
        j = partition(arr,low,high);
        quick_sort(arr,low,j);
        quick_sort(arr,j+1,high);
    }
}

void main(){
    int size, *arr;
     printf("Name : Ajay Joshi\nEnrollment No. : 92201703192\n\n");
    printf("\n................Quicksort...................\n\n");
    printf("Enter size of array  : ");
    scanf("%d",&size);

    arr = (int *)malloc(size*sizeof(int));

    printf("Enter element of array :\n");
    for(int i =0; i < size; i++){
        scanf("%d", &arr[i]);
    }

    quick_sort(arr,0,size-1);

    printf("\nSorted array is : \n");
    for(int i =0; i < size; i++){
        printf("%d  ",arr[i]);
    }


}