#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int *ans;

void merge(int *arr, int low, int mid, int high){
    int i = low;
    int j=mid+1;
    int k =0;

    while(i<=mid && j<=high){
        if(arr[i]<= arr[j]){
            ans[k] = arr[i];
            i++;
            k++;
        }
        else{
            ans[k] = arr[j];
            j++;
            k++;
        }
    }
        while(j <= high){
            ans[k] = arr[j];
            k++;
            j++;
        }

        while(i<= mid){
            ans[k] = arr[i];
            i++;
            k++;
        }
    k=0;
    for(i = low; i<=high; i++){
        arr[i] = ans[k];
        k++;
    }
}

void partition(int * arr, int low, int high){
    if(low<high){
        int mid = (low+high)/2;
        partition(arr,low,mid);
        partition(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}

void merge_sort(int *arr, int n){
        partition(arr, 0, n-1);
}


void main(){
    int size;
     printf("Name : Ajay Joshi\nEnrollment No. : 92201703192\n\n");
    printf("\n................Mergesort...................\n\n");
    printf("Enter size of array  : ");
    scanf("%d",&size);

    int *arr = (int *)malloc(size*sizeof(int));
    ans = (int *)malloc(size*sizeof(int));
    printf("Enter element of array :\n");
    for(int i =0; i < size; i++){
        scanf("%d", &arr[i]);
    }

    merge_sort(arr,size);

    printf("\nSorted array is : \n");
    for(int i =0; i < size; i++){
        printf("%d  ",ans[i]);
    }


}