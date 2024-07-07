#include<stdio.h>

void swap(int *a, int *b){

    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int arr[], int n){
    
    int min;
    for (int i=0; i<n-1; i++){

        min = i;
        for (int j=i+1; j<n; j++){
            if (arr[j] < arr[min]){
                min = j;
            }
        }
        swap (&arr[min], &arr[i]);       
    }
}

int main(){

    int arr[] = {55, 88, 87, 69, 96, 109, 32, 76};
    int n = sizeof(arr)/sizeof(arr[0]);

    selectionSort(arr, n);
    printf("The selection sorted array is: ");
    for (int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }

}