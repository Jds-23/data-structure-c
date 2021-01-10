#include "stdio.h"
#include "malloc.h"
#include "stdlib.h"
struct node{
	int data;
	struct node *next;
	struct node *prv;
};
void display(struct node *start);
struct node *createlist(int n);
struct node *insertAtBegining(struct node *start);
void insertAtPos(struct node *start);
void insertAtEnd(struct node *start);
void deleteAtEnd(struct node *start);
struct node *deleteAtBegining(struct node *start);
main()
{
	int c,n;
	struct node *start;
	printf("\nEnter the size of list");
	scanf("%d",&n);
	start=createlist(n);
	printf("\nList Created Inserted");
	display(start);
	while(1)
	{
		
	printf("\nEnter the choice :0.Exit \n1.display \n2.InsertBegin \n3.insertEnd \n4.insertPos \n5.Delete At End \n6.Delete At Begining");
	scanf("%d",&c);
	switch(c)
	{
		case 0:
			{
				exit(0);
			}
		case 1:
			{
				display(start);
				break;
			}
		case 2:
		    {
				start = insertAtBegining(start);
				printf("\nNode Inserted");
				display(start);
				break;
			}
		case 3:
			{
				insertAtEnd(start);
				printf("\nNode Inserted");
				display(start);
				break;
			}
		case 4:
			{
				insertAtPos(start);
				printf("\nNode Inserted");
				display(start);
				break;
			}
		case 5:
			{
				deleteAtEnd(start);
				printf("\nNode Deleted");
				display(start);
				break;
			}
			case 6:
				{
					start=deleteAtBegining(start);
					printf("\nNode Deleted");
					display(start);
					break;
				}
	}
	}
}
struct node *createlist(int n)
{
	struct node *start=NULL;
	start=insertAtBegining(start);
	while(--n)
	{
		insertAtEnd(start);
	}
	return start;
}
struct node *insertAtBegining(struct node *start)
{
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	printf("Enter data ");
	scanf("%d",&(temp->data));
	temp->next=start;
	temp->prv=NULL;
	if(start!=NULL)
	start->prv=temp;
	return temp;
}

void insertAtEnd(struct node *start)
{
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	printf("Enter data ");
	scanf("%d",&(temp->data));
	temp->next=NULL;
	while(start->next!=NULL)
	{
		start=start->next;
	}
	start->next=temp;
	temp->prv=start;
}
void insertAtPos(struct node *start)
{
	struct node *temp;
	int k,x=1;
	temp = (struct node *)malloc(sizeof(struct node));
	printf(" Enter data ");
	scanf("%d",&(temp->data));
	printf("Enter at position");
	scanf("%d",&k);
	while(start!=NULL&&x<k)
	{
		start=start->next;
		x++;
	}
	if(start==NULL)
	{
		printf("Node doesn't exist");
		return;
	 }
	 temp->next=start->next;
	 start->next->prv=temp;
	 temp->prv=start;
	 start->next=temp;
}
void display(struct node *start)
{
		while(start!=NULL)
	{
		printf("%d->",start->data);
		start=start->next;
	}
}
void deleteAtEnd(struct node *start)
{
	struct node *temp;
	if(start->next=NULL)
	{
		free(start);
		}
	while(start->next->next!=NULL)
	{
		start=start->next;
	}
	temp=start->next;
	start->next=NULL;
	free(temp);
}
struct node *deleteAtBegining(struct node *start)
{
	struct node *temp;
	temp=start->next;
	start->next->prv=NULL;
	free(start);
	return temp;
}
