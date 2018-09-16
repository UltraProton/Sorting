#include <stdio.h>

#define size 10

void swap(int *a, int *b){
	int t=*a;
	*a=*b;
	*b=t;
}

void InsertionSort(int *arr){
	int i=1;
	for(;i<size;i++){
		int j=i-1;

		while(j>=0 && arr[j]>arr[j+1]){
			swap((arr+j),(arr+(j+1)));
			j--;
		}		
	}
}

void InsertionSortCormen(int *arr){
	int i=1;
	for(;i<size;i++){
		int key=arr[i];
		int j=i-1;

		while(j>=0 && arr[j]>key){
			arr[j+1]=arr[j]