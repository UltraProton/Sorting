#include<stdio.h>

void swap(int *a,int *b){
    int t=*a;
    *a=*b;
    *b=t;
}

int HoarePartition(int * arr, int l, int r){
    int x=arr[l];
    int i=l-1;
    int j=r+1;

    while(1){
 
      do{
        i++;
    }while(arr[i] < x);

 
    do{
        j--;
    }while(arr[j]>x);

 
    if(i<j)
        swap(&arr[i],&arr[j]);
    else
        return j;
}
}

void QuickSort(int *arr,int l,int r){
    int p=0;
    if(l<r){
        p=HoarePartition(arr,l,r);
        QuickSort(arr,l,p);
        QuickSort(arr,p+1,r);
    }
}


int main(void){
    int arr[]={13,19,9,5,12,8,7,4,11,2,6,21};
    int size=sizeof(arr)/sizeof(arr[0]);
    int i=0;
    QuickSort(arr,0,size-1);
    for(;i<size;i++){
        printf("%d ",arr[i]);
    }

    return 0;
}
