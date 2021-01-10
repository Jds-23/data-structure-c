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
void display(struct queue *Q);
int dequeue(struct queue *Q);
void enqueue(struct queue *Q,int x);
int Isqueueempty(struct queue *Q);
void deletequeue(struct queue *Q);
struct queue *createqueue();
main()
{
	int ch,x;
	struct queue *Q=createqueue();	
	while(1)
	{
		printf("\nEnter Choice :\n0.Exit \n1.Insert \n2.Delete \n3.Front & Rear \n4.Display \n5.Delete Stack");
		scanf("%d",&ch);
		switch(ch)
		{
			case 0:
				{
					exit(0);
				}
			case 1:
				{
					printf("\n Enter Data ");
					scanf("%d",&x);
					enqueue(Q,x);
					printf("\n Element Inserted ");
					display(Q);
					break;
				}
			case 2:
				{
					x=dequeue(Q);
					if(x==INT_MIN)
					{
					printf("\nQueue Underflow");
					break;
					}
					printf("%d ",x);
					printf("\n Element Deleted ");
					display(Q);
					break;
				}
			/*case 3:
				{
					x=peek();
					if(x==INT_MIN)
					{
					printf("\nStack Underflow");
					break;
				}
					printf("%d ",x);
					printf("\n Element Peeked ");
					break;
					
				}*/
			case 4:
				{
					display(Q);
					break;
				}
			case 5:
				{
					deletequeue(Q);
					printf("Queue Deleted");
				}
		}
	}

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
void display(struct queue *Q)
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	if(Isqueueempty(Q))
	{
		printf("NO elements in Queue");
		return;
	}
	temp=Q->front;
	do
	{
		printf("  %d",temp->data);
		temp=temp->next;
	}while(temp!=NULL);
}
void deletequeue(struct queue *Q)
{
	struct node *head=Q->front,*temp;
		while(head->next)
	{
		temp=head->next;
		head->next=temp->next;
		free(temp);
	}
	free(head);
	Q->front=Q->rear=NULL;
}
int Isqueueempty(struct queue *Q)
{
	return Q->front==NULL;
}
