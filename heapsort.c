#include<stdio.h>

void MAX_HEAPIFY(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}



void BUILD_MAX_HEAP(int arr[], int n, int i){
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;
    if(2*i+1<n && arr[left]>arr[largest]){
        MAX_HEAPIFY(&arr[left], &arr[largest]);
        BUILD_MAX_HEAP(arr, n , left);
    }
    if(2*i+2<n && arr[right]>arr[largest]){
        MAX_HEAPIFY(&arr[right], &arr[largest]);
        BUILD_MAX_HEAP(arr, n, right);
    }
}

void HEAPSORT(int arr[], int n, int j){
    if(j == n-1) return;
    for(int i = (n-j)/2-1; i>=0; i--){
        BUILD_MAX_HEAP(arr, n-j, i);
    }
    MAX_HEAPIFY(&arr[n-1-j], &arr[0]);
    HEAPSORT(arr, n, j+1);

}

int main(){
    int n = 6;
    int arr[] = {1,2,3,9,44,5,6};
    
    HEAPSORT(arr, n, 0);
    for(int i = 0; i<n; i++){
        printf("%d ", arr[i]);
    }printf("\n");

    return 0;
}