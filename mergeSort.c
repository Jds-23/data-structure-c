#include "stdio.h"
#include "malloc.h"
void mergeSort(int *arr,int low,int high);
void merge(int *arr,int ,int ,int);
void copy(int *arr,int *temp,int low,int high);

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
	mergeSort(arr,0,N-1);
	for(i=0;i<N;i++){
	printf(" %d ",arr[i]);
	}
	}
	return 0;
}

void mergeSort(int *arr,int low,int high){
	int mid;
	if(low<high){
		mid=(high+low)/2;
		mergeSort(arr,low,mid);
		mergeSort(arr,mid+1,high);
		merge(arr,low,mid,high);
	}
}

void merge(int *arr,int low,int mid,int high){
	int i=low,j=mid+1,k=0,N=(high-low)+1,*temp,x=0;
	temp=(int *)malloc(sizeof(int)*N);
	while(k<N){
		if(i<=mid&&j<=high){
			if(arr[i]<=arr[j]){
				temp[k]=arr[i];
				i++;
			}
			else{
				temp[k]=arr[j];
				j++;
			}
		}
		else if(i<=mid){
			temp[k]=arr[i];
			i++;
		}
		else{
			temp[k]=arr[j];
			j++;
		}
		k++;
		
	}
	copy(arr,temp,low,high);
}

void copy(int *arr,int *temp,int low,int high){
	int i=0,j=low;
	while(j<=high){
		arr[j]=temp[i];
		i++,j++;
	}
}
