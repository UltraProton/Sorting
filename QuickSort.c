#include<stdio.h>
#include <stdlib.h>
#include <time.h>

#define n 1000000

void QSLomuto(long long *, long long ,long long );
void QSHoare1(long long *, long long, long long);
void QSHoare2(long long *, long long, long long);
long long HoarePartition(long long *,long long, long long);
long long LomutoPartition(long long *, long long, long long);
long long LomutoPartitionDec(long long *, long long ,long long);
void PrintArr(long long *);
void swap(long long *, long long *);
void QSLomutoDecreasing(long long *, long long, long long);

int main(void){

	clock_t start,end;

//	long long arr[]={5,3,-6,8,0};

	long long *arr1=(long long *)malloc(sizeof(long long)*n);
	long long *arr2=(long long *)malloc(sizeof(long long)*n);


	FILE *infile= fopen("QSInput1.txt","r");

	long long i=0;

     while (i<n){
        fscanf(infile,"%lld",&arr1[i]);
          i++;
    }

    i=0;

     while (i<n){
        fscanf(infile,"%lld",&arr2[i]);
          i++;
    }

    start=clock();
    QSLomuto(arr1,0,n-1);
    end=clock();

    printf("Time taken by LomutoPartition:%f\n",((double)(end-start)/CLOCKS_PER_SEC));

//    PrintArr(arr,n);


//x=sizeof(arr)/sizeof(arr[0]);

    free(arr1);

    start=clock();
    QSHoare1(arr2,0,n);
    end=clock();

    //PrintArr(arr);

    printf("Time taken by HoarePartition:%f\n",((double)(end-start)/CLOCKS_PER_SEC));

    /*start=clock();
    QSLomutoDecreasing(arr,0,n);
    end=clock();

    PrintArr(arr);

    printf("Time taken by LomutoPartition:\n Time taken by HoarePartition: %f %f\n",((double)(end-start)/CLOCKS_PER_SEC));

    free(arr);

    arr=NULL;
*/

   free(arr2);

    return 0;

}

void PrintArr(long long *arr){
	long long i=0;
	for ( i = 0; i < n; ++i)
	{
		printf("%lld ",arr[i] );
	}

	printf("\n");
}


// selecting rightmost element as pivot
// It has to be coded carefully as it might give segmentation fault
long long HoarePartition1(long long *arr,long long l,long long r ){
	long long pivot=arr[r];
	long long i=l-1;
	long long j=r+1;

	while(1){

		do{
			i++;
		}while(arr[i]<pivot);

		do{
			j--;
		}while(j>0 && arr[j]>pivot); // j>0 is the extra condition

		if(i>=j)
			return i;
		else
			swap(&arr[i],&arr[j]);
	}
}

//Selecting leftmost element as the pivot
//Note the differences in Hoare Partition 1 and 2
// Dry run HoarePartition2 on {5,3-6,8,0}
long long HoarePartition2(long long *arr,long long l,long long r ){
	long long pivot=arr[l];
	long long i=l-1;
	long long j=r+1;

	while(1){

		do{
			i++;
		}while(arr[i]<pivot);

		do{
			j--;
		}while(arr[j]>pivot); // j>0 is the extra condition

		if(i>=j)
			return j;
		else
			swap(&arr[i],&arr[j]);
	}
}



void QSHoare1(long long *arr,long long l, long long r){
//	long long pivotIndex=0;
	if(l < r){
		long long pivotIndex=HoarePartition1(arr,l,r);
		//QSHoare1(arr,l,pivotIndex-1);
        QSHoare1(arr,l,pivotIndex-1);
		QSHoare1(arr,pivotIndex,r);
	}

}


void QSHoare2(long long *arr,long long l, long long r){
//	long long pivotIndex=0;
	if(l < r){
		long long pivotIndex=HoarePartition2(arr,l,r);
		QSHoare2(arr,l,pivotIndex);
		QSHoare2(arr,pivotIndex+1,r);
	}

}

void swap(long long *a, long long *b){
	long long temp=*a;
	*a=*b;
	*b=temp;
}

long long LomutoPartition(long long *arr, long long l, long long r){
	long long i=l-1;
	long long j=l;
	long long pivot = arr[r];

	while(j<=r-1){
		if(arr[j]<=pivot){
			i=i+1;
			swap(&arr[i],&arr[j]);
		}

		j=j+1;
	}

	swap(&arr[r],&arr[i+1]);

	return i+1;
}

void QSLomuto(long long *arr, long long l, long long r){
	if(l<r){
		long long pivotIndex=LomutoPartition(arr,l,r);
		QSLomuto(arr,l,pivotIndex-1);
		QSLomuto(arr,pivotIndex+1,r);
	}
}

void QSLomutoDecreasing(long long *arr, long long l, long long r){
	if(l<r){
		long long pivotIndex=LomutoPartitionDec(arr,l,r);
		QSLomutoDecreasing(arr,l,pivotIndex-1);
		QSLomutoDecreasing(arr,pivotIndex+1,r);
	}
}



long long LomutoPartitionDec(long long *arr, long long l, long long r){
	long long i=l-1;
	long long j=l;
	long long pivot = arr[r];

	while(j<=r-1){
		if(arr[j]>pivot){
			i=i+1;
			swap(&arr[i],&arr[j]);
		}

		j=j+1;
	}

	swap(&arr[r],&arr[i+1]);

	return i+1;
}

