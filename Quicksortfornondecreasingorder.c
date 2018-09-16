#include<stdio.h>

void swap(int * a, int *b){
int t=*a;
*a=*b;
*b=t;
}


int partition(int *A, int left, int right){
int x=A[right] , i=left-1 ,  j=0  ;

   for(j=left ; j <= right-1; j++){
      if(A[j]>=x){
            i++;
            swap(&A[i],&A[j]);
      }
   }
   swap(&A[i+1],&A[right]);
return i+1;
}

void QS(int *arr, int left,int right){
if(left<right){
int p=partition(arr,left,right);
QS(arr,0,p-1);
QS(arr,p+1,right);
}
}

int main(void){
int arr[]={1,2,2,3,4,5,6,6,6,7,8,9};
int i=0;

QS(arr,0,11);

while(i<12){
printf("%d ",arr[i]);
i++;
}

return 0;

}

