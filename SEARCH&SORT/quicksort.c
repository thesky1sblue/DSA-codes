// #include<stdio.h>

// void swap(int *x, int *y);
// void quicksort(int arr[], int length);
// void quicksort_recursion(int arr[], int low, int high);
// int partition(int arr[], int low, int high);

// int main(){
//     int arr[]={10,11,23,44,8,15,3,9,12,45,56,45,45};
//     int length=13;

//     quicksort(arr,length);
//     for (int i=0; i<length;i++)
//     {
//         printf("%d\n", arr[i]); /// printing out elements in arr at each index
//     }
// }

// void swap(int *x, int *y)
// {
//     int temp= *x;
//     *x=*y;
//     *y=temp;
// }

// void quicksort(int arr[], int length){
//     quicksort_recursion(arr,0,length-1);
// }

// void quicksort_recursion(int arr[], int low, int high){
//     if (low<high)
//     {
//         int pivot_index=partition(arr, low, high);
//         quicksort_recursion(arr,low,pivot_index-1);
//         quicksort_recursion(arr,pivot_index+1, high);
//     }
// }

// int partition(int arr[], int low, int high){
//     int pivot_value=arr[high];
//     int i=low;
//     for (int j=low;j<high;j++)
//     {
//         if (arr[j]<=pivot_value)
//         {
//             swap(&arr[i], &arr[j]);
//             i++;

//         }
//     }
//     swap(&arr[i],&arr[high]);
//     return i;



// }
// --------------------- WITHOUT USING quicksort_recursion ------------------------
#include <stdio.h>

// function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// partition function
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // choose last element as pivot
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

// quicksort function
void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

int main() {
    int arr[] = {10, 11, 23, 44, 8, 15, 3, 9, 12, 45, 56, 45, 45};
    int n = sizeof(arr) / sizeof(arr[0]);

    quicksort(arr, 0, n - 1);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

