#include<stdio.h>

// Function prototype
void swap(int *p, int *q);

void display(int arr[], int n) {
    for(int i=0; i<n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void heapify(int arr[], int n, int i){
    int max = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n && arr[left] > arr[max])
    {
        max = left;
    }

    if(right < n && arr[right] > arr[max])
    {
        max = right;
    }

    if(max != i)
    {
        swap(&arr[i], &arr[max]);
        heapify(arr, n, max);
    }
}

void swap(int *p, int *q) {
    int temp = *p;
    *p = *q;
    *q = temp;
}

void heapSort(int arr[], int n){
    int i;

    // Build max heap
    for(i=n/2-1; i>=0; i--)
    {
        heapify(arr, n, i);
    }

    // Extract elements
    for(i=n-1; i>=0; i--)
    {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

int main(){
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Before sorting: \n");
    display(arr, n);

    heapSort(arr, n);

    printf("After sorting: \n");
    display(arr, n);

    return 0;
}