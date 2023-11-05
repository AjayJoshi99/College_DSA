#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

void bublesort(int *arr,int  n){
    for(int i =0; i <n-1; i++){
        bool check = false;
        for(int j =0; j<n-i-1; j++){
                if(arr[j]>arr[j+1]){
                    check = true;
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1]= temp;
                }
        }
        if(!check){
            break;
        }
    }
}


void main(){
    int size;
    printf("Name : Ajay Joshi\nEnrollment No. : 92201703192\n\n");
    printf("\n................Bubblesort...................\n\n");
    printf("Enter size of array  : ");
    scanf("%d",&size);

    int *arr = (int *)malloc(size*sizeof(int));

    printf("Enter element of array :\n");
    for(int i =0; i < size; i++){
        scanf("%d", &arr[i]);
    }

    bubleshort(arr,size);

    printf("\nSorted array is : \n");
    for(int i =0; i < size; i++){
        printf("%d  ",arr[i]);
    }


}