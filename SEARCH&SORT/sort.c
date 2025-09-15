#include<stdio.h>
#include<string.h>

int main(void){
    int a[]={2,1,6,3,5,9,8};
    int length=7;

    bubblesort(a,length);
    insertsort(a,length);

    for (int i=0;i<length;i++){
        printf("a[%d]=%d\n",i,a[i]);
    }
        
    return 0;
}

void bubblesort(int a[], int length){
        for(int i=0; i<length;i++)
    {
        for (int j=0;j<(length -1);j++)
        {
            if (a[j]>a[j+1]){
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}

void insertsort(int a[], int length){
    for(int i=1; i<length;i++){
        int key=a[i]; // 1st element is the key
        int j=i-1;

        while(j>=0 && a[j]>key){
            a[j+1]=a[j];
            j=j-1;


        }
        a[j+1]=key;

    }
}

void selectionsort(int a[], int length)
{
    for (int i = 0; i < (length - 1); i++)
    {
        int min_pos = i;
        for (int j = i + 1; j < length; j++)
        {
            if (a[j] < a[min_pos])
            {
                min_pos = j;
            }
        }
        // Swap after finding the minimum
        if (min_pos != i)
        {
            int temp = a[i];
            a[i] = a[min_pos];
            a[min_pos] = temp;
        }
    }
}
// void mergesort(int a[], int length){
//     mergesortrecursion(a,0,length-1);
// }

// void mergesortrecursion(int a[], int l, int r)
// {
//     if (l<r)
//     {
//     int middle =l+(r-l)/2;

//     mergesortrecursion(a,l,middle);
//     mergesortrecursion(a, middle+1,r);

//     merge_sorted_arrays(a,l,middle,r);
//     }
// }

// void merge_sorted_arrays(int a[], int l, int r, int middle)
// {
//     int left_length=(middle-l)+1;
//     int right_length=r-middle;

//     int temp_left[left_length];
//     int temp_right[right_length];

//     int i,j,k;

//     for (int i=0; i<left_length;i++){
//         temp_left[i]=a[l+i];
//     }

//     for (int i=0; i<right_length;i++){
//         temp_right[i]=a[middle + 1 + i];
//     }
//     for (i=0,j=0,k=l;k<=r;k++){
//         //// incomplete //////

//     }


// }




