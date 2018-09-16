#include<stdio.h>

#define size 13

void Merge(int arr[],int l, int m, int r){
	int n1=m-l+1; // Here n1 should be m-l+1 only not m-l and n2 should be r-m and not r-m+1...to verify see the case when l =8 and r=15 => m=8+3=11 
	             //  n1= m-l=11-8=3 and n2= 15-11+1=5 which makes it 8 elements but we only have 7 in our case 

	int n2=r-m;

	int arr1[n1];
	int arr2[n2];

	int i=0,j=0,k=0;

	while(i<n1){
		arr1[i]=arr[l+i];
		i++;
	}

	while(j<n2){
		arr2[j]=arr[m+1+j];
		j++;
	}

	i=0;
	j=0;
	k=l;

	while(i<n1 && j<n2){
		if(arr1[i]<=arr2[j]){
			arr[k]=arr1[i];
			i++;
		}

		else{
			arr[k]=arr2[j];
			j++;
		}

		k++;
	}

	while(i<n1){
		arr[k]=arr1[i];
		k++;
		i++;
	}

	while(j<n2){
		arr[k]=arr2[j];
		k++;
		j++;
	}

}

void MergeSort(int *arr,int l, int r){
	int m=l+(r-l)/2;
	
	if(l<r){
	MergeSort(arr,l,m);
	MergeSort(arr,m+1,r);
	Merge(arr,l,m,r);
	}

}


int main(void){
	
	int arr[size]={10,9,8,7,6,5,4,3,2,1,-100,9,345};

	MergeSort(arr,0,size-1);

	int i=0;

	while(i<size){
		printf(" %d",arr[i] );
		i++;
	}

	return 0;
}
