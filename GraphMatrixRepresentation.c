#include "stdio.h"
#include "malloc.h"
#include "stdlib.h"
struct node{
	int data;
	struct node *next;
}; 
struct queue{
	struct node *rear,*front;
};

int dequeue(struct queue *Q);
void enqueue(struct queue *Q,int x);
int Isqueueempty(struct queue *Q);
struct queue *createqueue();

void dfsTraversal(int *arr,int V,int N,int *visited);
void dfs(int *arr,int V,int N);
void bfs(int *arr,int V,int N);
void bfs(int *arr,int V,int N){
	int i;
	struct queue *Q=createqueue();	
	int *visited=malloc(sizeof(int)*N);
	for(i=0;i<N;i++){
	visited[i]=0;
	}
	enqueue(Q,V);
	visited[V]=1;
	printf("/nThe BFS Traversal/n");
	while(Isqueueempty(Q)==0){
		V=dequeue(Q);
		printf(" %d ",V);
		for(i=0;i<N;i++){
		if(*(arr+(V*N)+i)==1&&visited[i]==0){
			enqueue(Q,i);
			visited[i]=1;
		}
		}
	}
	
}
void dfs(int *arr,int V,int N){
	int i;
	int *visited=malloc(sizeof(int)*N);
	for(i=0;i<N;i++){
	visited[i]=0;
	}
	printf("/nThe DFS Traversal/n");
	dfsTraversal(arr,V,N,visited);
}
void dfsTraversal(int *arr,int V,int N,int *visited){
	int i;
	
	visited[V]=1;
	printf(" %d ",V);
	for(i=0;i<N;i++){
		if(*(arr+(N*V)+i)==1&&visited[i]==0)
	dfsTraversal(arr,i,N,visited);
	}
}

int main(){
	int N,i,j,x;
	int *arr;
	printf("Enter the no of Vertices Graph:");
	scanf("%d",&N);
	//N=7
	arr=(int *)malloc(sizeof(int)*N*N);
	
	for(i=0;i<N;i++){
		while(1){	
	printf("\nEnter the edge %d: ",i);
	scanf("%d",&x);
	if(x==-1)
	break;
	*(arr+(N*i)+x)=1;	
		}
	}
	printf("\nThe Matrix\n");
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			if(*(arr+(N*i)+j)!=1)
			*(arr+(N*i)+j)=0;
			printf(" %d ",*(arr+(N*i)+j));
		}
		printf("\n");
	}
	printf("\n\n");
	dfs(arr,0,N);
	bfs(arr,0,N);
	return 0;
}


struct queue *createqueue()
{
	struct queue *Q=(struct queue *)malloc(sizeof(struct queue));
	Q->front=NULL;
	Q->rear=NULL;
	return Q;
}
void enqueue(struct queue *Q,int x)
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->data=x;
	temp->next=NULL;
	if(Isqueueempty(Q))
	{
		Q->front=Q->rear=temp;
		return;
	}
	Q->rear->next=temp;
	Q->rear=temp;
	return;
}
int dequeue(struct queue *Q)
{
	struct node *temp;
	int x;
	temp=(struct node *)malloc(sizeof(struct node));
	if(Isqueueempty(Q))
	return INT_MIN;
	temp=Q->front;
	x=temp->data;
	Q->front=temp->next;
	if(Q->front==NULL)
	Q->rear=NULL;
	free(temp);
	return x;
}

int Isqueueempty(struct queue *Q)
{
	return Q->front==NULL;
}
