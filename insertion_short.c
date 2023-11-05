#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void insertion_sort(int *arr, int n){
    int i,j,temp;
    for(i =1; i<n; i++){
        j=i-1;
        while(j>=0 && arr[j]>arr[j+1]){
            temp = arr[j+1];
            arr[j+1] = arr[j];
            arr[j] = temp;
            j-=1;
        }
    }
}


void main(){
    int size;
    printf("Enter size of array  : ");
    scanf("%d",&size);

    int *arr = (int *)malloc(size*sizeof(int));

    printf("\nEnter element of array :\n");
    for(int i =0; i < size; i++){
        scanf("%d", &arr[i]);
    }

    insertion_sort(arr,size);

    printf("\nSorted array is : \n");
    for(int i =0; i < size; i++){
        printf("%d  ",arr[i]);
    }

}