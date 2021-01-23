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
void floydWarshall(int *arr,int N);
int dequeue(struct queue *Q);
void enqueue(struct queue *Q,int x);
int Isqueueempty(struct queue *Q);
struct queue *createqueue();
void undirectedCycle(int *arr,int V,int N);
void dijsktra(int *arr,int V,int N);
int minDistVertex(int *dist,int *selected,int N);

void dfsTraversal(int *arr,int V,int N,int *visited);
void dfs(int *arr,int V,int N);
void bfs(int *arr,int V,int N);

int main(){
	int N,i,j,x,D,W,weight;
	//int *arr;
	//printf("Enter the no of Vertices Graph:");
	//scanf("%d",&N);
	N=4;
	//arr=(int *)calloc(sizeof(int),N*N);
	/*int arr[81]={ 0, 4, 0, 0, 0, 0, 0, 8, 0 , 4, 0, 8, 0, 0, 0, 0, 11, 0 , 0, 8, 0, 7, 0, 4, 0, 0, 2 ,0, 0, 7, 0, 9, 14, 0, 0, 0 , 0, 0, 0, 9, 0, 10, 0, 0, 0 , 
                         0, 0, 4, 14, 10, 0, 2, 0, 0 , 
                         0, 0, 0, 0, 0, 2, 0, 1, 6 , 
                         8, 11, 0, 0, 0, 0, 1, 0, 7 , 
                         0, 0, 2, 0, 0, 0, 6, 7, 0 };
	*/
	int arr[16]={0,9,-4,0
				,6,0,0,2
				,0,5,0,0
				,0,0,1,0};
	
	printf("\n1. Directed Graph\n 0. Undirected Graph");
	scanf("%d",&D);
	printf("\n1. Weighted Graph\n 0. UnWeighted Graph");
	scanf("%d",&W);
	
	/*
	for(i=0;i<N;i++){
		while(1){	
		
			if(W==1){
				printf("\nEnter the edge and Weight %d: ",i);
				scanf("%d",&x);
				if(x==-1)
				break;
				scanf("%d",&weight);
				*(arr+(N*i)+x)=weight;
				if(D==0)
					*(arr+(N*x)+i)=weight;	
			}
			else{
				printf("\nEnter the edge %d: ",i);
				scanf("%d",&x);
				if(x==-1)
				break;
				*(arr+(N*i)+x)=1;
				if(D==0)
					*(arr+(N*x)+i)=1;	
			}
			
		}
	}
	*/
	
	
	printf("\nThe Matrix\n");
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
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
	dijsktra(arr,0,N);
	floydWarshall(arr,N);
	return 0;
}

void floydWarshall(int *arr,int N){
	int dist[N][N];
	int i,j,k;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			if(i==j)
			dist[i][j]=0;
			else if(*(arr+(N*i)+j)==0)
			dist[i][j]=INT_MAX;
			else
			dist[i][j]=*(arr+(N*i)+j);
		}
	}
	
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			for(k=0;k<N;k++){
			if(i!=j&&i!=k){
				if(dist[j][i]!=INT_MAX&&dist[i][k]!=INT_MAX&&dist[j][k]>dist[j][i]+dist[i][k]){
					dist[j][k]=dist[j][i]+dist[i][k];
				}
			}
			}
		}
	}
	
	for(i=0;i<N;i++){
		printf("\n%d :",i);
		for(j=0;j<N;j++){
			printf(" %d ",dist[i][j]);
		}
	}
}


void dijsktra(int *arr,int V,int N){
	int *dist=(int *)malloc(sizeof(int)*N),*selected=(int *)malloc(sizeof(int)*N);
	int i,u,v;	
	for (i = 0; i < N; i++) 
        dist[i] = INT_MAX, selected[i] = 0; 
        
    dist[V] =0;
    
    for (i = 0; i < N; i++){
    	
    	u=minDistVertex(dist,selected,N);
    	selected[u] = 1;
    	
    	for(v=0;v<N;v++){
    		if(selected[v]==0&&*(arr+(N*u)+v)!=0&&dist[u]!=INT_MAX&&dist[v]>dist[u]+*(arr+(N*u)+v)){
    			dist[v]=dist[u]+*(arr+(N*u)+v);
			}
		}
	}
		printf("\n\nE   D\n");
	for (i = 0; i < N; i++){
		printf("%d   %d\n",i,dist[i]);
	}
}

int minDistVertex(int *dist,int *selected,int N){
	int min=INT_MAX,minIndex,i;
	
	for(i=0;i<N;i++){
		
		if(selected[i]==0&&dist[i]<min)
		{
			min=dist[i];
			minIndex=i;
		}
	}
	
	return minIndex;
}


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
		if(*(arr+(V*N)+i)!=0&&visited[i]==0){
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
		if(*(arr+(N*V)+i)!=0&&visited[i]==0)
	dfsTraversal(arr,i,N,visited);
	}
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
		if(*(arr+(V*N)+i)!=0&&visited[i]==-1){
			enqueue(Q,i);
			visited[i]=0;
		}
		else if(*(arr+(V*N)+i)!=0&&visited[i]==0){
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
		if(*(arr+(N*V)+i)!=0&&visited[i]==-1)
			directedCycleDetector(arr,i,N,visited);
		else if(*(arr+(N*V)+i)!=0&&visited[i]==0)
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
