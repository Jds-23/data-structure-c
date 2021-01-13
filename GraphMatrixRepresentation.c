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
void directedCycle(int *arr,int V,int N);
void directedCycleDetector(int *arr,int V,int N,int *visited);
int dequeue(struct queue *Q);
void enqueue(struct queue *Q,int x);
int Isqueueempty(struct queue *Q);
struct queue *createqueue();
void undirectedCycle(int *arr,int V,int N);

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
	printf("\nThe BFS Traversal\n");
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
	printf("\nThe DFS Traversal\n");
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
	int N,i,j,x,D;
	int *arr;
	printf("Enter the no of Vertices Graph:");
	scanf("%d",&N);
	//N=7
	arr=(int *)malloc(sizeof(int)*N*N);
	
	printf("\n1. Directed Graph\n 0. Undirected Graph");
	scanf("%d",&D);
	
	for(i=0;i<N;i++){
		while(1){	
			printf("\nEnter the edge %d: ",i);
			scanf("%d",&x);
			if(x==-1)
				break;
			*(arr+(N*i)+x)=1;
			if(D==0)
				*(arr+(N*x)+i)=1;	
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
	
	if(D==1)
	directedCycle(arr,0,N);
	else
	undirectedCycle(arr,0,N);
	return 0;
}
void undirectedCycle(int *arr,int V,int N){
	int i;
	struct queue *Q=createqueue();	
	int *visited=malloc(sizeof(int)*N);
	for(i=0;i<N;i++){
	visited[i]=-1;
	}
	enqueue(Q,V);
	visited[V]=0;
	printf("\nThe UnDirect Graph Cycle\n");
	while(Isqueueempty(Q)==0){
		V=dequeue(Q);
		visited[V]=1;
		for(i=0;i<N;i++){
		if(*(arr+(V*N)+i)==1&&visited[i]==-1){
			enqueue(Q,i);
			visited[i]=0;
		}
		else if(*(arr+(V*N)+i)==1&&visited[i]==0){
				printf("\nCycle Detected %d to %d\n",V,i);
		}
		}
	}
	
}


void directedCycle(int *arr,int V,int N){
	int i;
	int *visited=malloc(sizeof(int)*N);
	for(i=0;i<N;i++){
	visited[i]=-1;
	}
	printf("\nThe Cycle\n");
	directedCycleDetector(arr,V,N,visited);
}
void directedCycleDetector(int *arr,int V,int N,int *visited){
	int i;
	
	visited[V]=0;
	for(i=0;i<N;i++){
		if(*(arr+(N*V)+i)==1&&visited[i]==-1)
			directedCycleDetector(arr,i,N,visited);
		else if(*(arr+(N*V)+i)==1&&visited[i]==0)
			{
				printf("\nCycle Detected %d to %d\n",V,i);
			}
	}
	visited[V]=1;
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
