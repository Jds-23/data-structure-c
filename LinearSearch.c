#include "stdio.h"
#include "malloc.h"
int main(){
	int *arr,N,i,num,pos=-1;
	printf("Enter the number the elements: ");
	scanf("%d",&N);
	arr=(int *)malloc(sizeof(int)*N);
	for(i=0;i<N;i++){
		printf("Enter the %d element: ",i+1);
		scanf("%d",&arr[i]);
	}

	printf("Enter the number you want to search: ");
	scanf("%d",&num);
	for(i=0;i<N;i++){
	if(arr[i]==num){
		pos=i;
	}
	}
	if(pos==-1)
	printf("Element not found\n");
	else
	printf("Element found at %d\n",pos);

	return 0;
}
