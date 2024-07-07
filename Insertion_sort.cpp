#include<stdio.h>

void insertionSort(int arr[], int n){

    int i, key, j;
    for (i=1; i<n; i++){
        key = arr[i];
        j = i-1;

        while (j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = key;
    }
}

int main(){

    int arr[] = {55, 88, 87, 69, 96, 109, 32, 76};
    int n = sizeof(arr)/sizeof(arr[0]);

    insertionSort(arr, n);
    printf("The insertion sorted array is: ");
    for (int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
}