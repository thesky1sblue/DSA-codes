#include <stdio.h>
#include <stdlib.h>

int linearsearch(int arr[], int length, int value);
int binarysearch(int a[], int left, int right, int value);

int main(void){
    int arr[]={1,3,5,6,2,4,7,8};
    int length=8;
    int index=linearsearch(arr,length,7);
    printf("Index is (using linearsearch) : %d\n", index);
    

    int a[6]={1,3,5,7,8,10};
    int indexx=binarysearch(a,0,5,7);
    printf("Index is (using binarysearch) : %d\n", indexx);
    return 0;
}

int linearsearch(int arr[], int length, int value){
    for (int i=0;i<length;i++)
    {
        if(arr[i]== value){
            return i;
        }
    }
    return -1;
}

int binarysearch(int a[], int left, int right, int value)
{
    int mid= left+(right-left)/2;
    
    if (left>right) return -1;

    if (a[mid]==value){
        return mid;
    }
    else if (a[mid]>value){ 
        return binarysearch(a, left, mid-1, value); 
        // right index is mid-1 now,,,,finds at the left hand side off arr
    }
    else {
        return binarysearch(a, mid+1, right, value);
        // left index is mid+1,,,,finds at the right hand side of arr  
    }

}
