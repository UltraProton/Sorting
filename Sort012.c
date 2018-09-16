#include <stdio.h>

#define size 13

/* loop invariant:

1. arr[0....left-1]=0
2. arr[left...mid-1]=1
3. arr[mid....right]=unknown
4. arr[right+1....high]
*/

int arr[size]={2,2,2,2,2,0,0,1,2,2,1,0,2};

void swap(int *a, int *b){
    int t=*a;
    *a=*b;
    *b=t;
}

void Sort012(int low,int high){
    int left=0;
    int mid=left;
    int right=high;

    while(mid<=right){
        switch(arr[mid]){
            case 0: swap(&arr[left],&arr[mid]);
                    left++;
                    mid++;
                    break;

            case 1: mid++;
                    break;

            case 2: swap(&arr[mid],&arr[right]);
                    right--;
                    break;
        }
    }
}

int main(void){
    int size1=0,i=0;
    size1=sizeof(arr)/sizeof(arr[0]);
    Sort012(0,size1-1);
    while(i<size1){
        printf("%d ",arr[i]);
        i++;
    }
    return 0;
}

