//wap to implement quick sort in c
#include <stdio.h> 
void display(int arr[], int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}
void insertionsort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
int main()
{
    int arr[]={5,6,12,32,10,9,4,11,15,7,2};
    const int n=sizeof(arr)/sizeof(arr[0]);
    printf("Before sorting: \n");
    display(arr,n);
    insertionsort(arr,n);
    printf("After sorting: \n");
    display(arr,n);
    return 0;
}