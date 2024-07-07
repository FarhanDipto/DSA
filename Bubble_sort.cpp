#include<stdio.h>

/*
    begin BubbleSort(array[n])

    for all elements of list
      if array[i] > array[i+1]
        swap(array[i], array[i+1])
      end of if
    end of for
   
   return array
end BubbleSort

Worst time complexity = 0(n^2)
*/

void swap(int *a, int *b){    

    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int n){

    int i, j, temp;
    for (i=0; i<n-1; i++){
        for (j=0; j<n-1-i; j++){
            if(arr[j]>arr[j+1]){
                swap(&arr[j], &arr[j+1]);
            }
        }

    }
}

int main(){
    
    int arr[] = {55, 88, 87, 69, 96, 109, 32, 76};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    bubbleSort(arr, n);
    printf("The bubble sorted array is: ");
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
}    