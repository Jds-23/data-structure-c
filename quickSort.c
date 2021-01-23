#include "stdio.h"
#include "malloc.h"
void quickSort(int *arr,int low,int high);
int partiton(int *arr,int low,int high);
void swap(int *a,int *b);

int main(){
	int *arr,N,i,num,pos=-1,T;
	scanf("%d",&T);
	while(T--){
	printf("\nEnter the number the elements: ");
	scanf("%d",&N);
	arr=(int *)malloc(sizeof(int)*N);
	for(i=0;i<N;i++){
		printf("Enter the %d element: ",i+1);
		scanf("%d",&arr[i]);
	}
	quickSort(arr,0,N-1);
	for(i=0;i<N;i++){
	printf(" %d ",arr[i]);
	}
	}
	return 0;
}

void quickSort(int *arr,int low,int high){
	int pivot,i;
	if(low<high){
	pivot=partition(arr,low,high);
	
	
	quickSort(arr,pivot+1,high);
	quickSort(arr,low,pivot-1);	
	}
}
int partition(int *arr,int low,int high){
	int j,i=low-1;
	
	for(j=low;j<=high;j++){
		if(arr[j]<=arr[high]){
			i++;
			swap(&arr[j],&arr[i]);
		}
	}
	return i;
}

void swap(int *a,int *b){
	int t=*a;
	*a=*b;
	*b=t;
}
