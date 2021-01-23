#include "stdio.h"
#include "malloc.h"
int main(){
	int *arr,N,i,num,pos=-1,low,mid,high;
	printf("Enter the number the elements: ");
	scanf("%d",&N);
	arr=(int *)malloc(sizeof(int)*N);
	for(i=0;i<N;i++){
		printf("Enter the %d element: ",i+1);
		scanf("%d",&arr[i]);
	}
	while(1){
	printf("Enter the number you want to search: ");
	scanf("%d",&num);
	low=0;
	high=N-1;
	pos=-1;
	while(high>=low){
		mid=(low+high)/2;
		if(arr[mid]==num){
			pos=mid;
			break;
		}
		else if(arr[mid]<num){
			low=mid+1;
		}
		else{
			high=mid-1;
		}
	}
	if(pos==-1)
	printf("Element not found\n");
	else
	printf("Element found at %d\n",pos+1);
}
	return 0;
}
