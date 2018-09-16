#include<stdio.h>

//void Min_Heapify(int * arr, int i,int n);
//void Build_MinHeap(int *arr,int n);
void Min_Heapify(int *arr,int i,int n){
    int l_index=2*i+1;
    int r_index=2*i+2;
    int smallest=i;

    if(l_index < n && arr[i] > arr[l_index])
        smallest=l_index;

    if (r_index < n && arr[smallest] > arr[r_index])
        smallest=r_index;

    if(smallest!=i){
        arr[i]=arr[i]+ arr[smallest];
        arr[smallest]=arr[i]-arr[smallest];
        arr[i]=arr[i]-arr[smallest];

        Min_Heapify(arr,smallest,n);
    }
}

void Build_MinHeap(int *arr,int n){
    int i=0;

    for(i=n/2-1 ; i>=0;i--){
        Min_Heapify(arr,i,n);
    }
}

void swap(int *a, int *b ){
      int t =*a;
      *a=*b;
      *b=t;
}

void HeapSort(int *arr,int n){
    int i=0, heapsize=n;
    Build_MinHeap(arr,n);
    while(i<n-1){
        swap(&arr[0],&arr[heapsize-1]);
        heapsize--;
        Min_Heapify(arr,0,heapsize);
        i++;
    }
}

int main(void){

    int arr[]={3,5,6,9,1,19,17,22,10};
    int i=0;

    HeapSort(arr,9);
    //Build_MinHeap(arr,9);

    while(i<9){
        printf("%d ",arr[i] );
        i++;
    }

return 0;
}

