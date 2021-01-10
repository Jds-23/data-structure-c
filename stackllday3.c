#include "stdio.h"
#include "malloc.h"
#include "stdlib.h"
struct node{
	int data;
	struct node *next;
};
struct stack{
	struct node *top;
};
void display(struct stack *S);
struct stack *createstack();
void push(struct stack *S,int);
int pop(struct stack *S);
int peek(struct stack *S);
int Isstackempty(struct stack *S);
main()
{
	int ch,x;
	struct stack *S;
	S=createstack();
	while(1)
	{
		printf("\nEnter Choice :\n0.Exit \n1.Push \n2.Pop \n3.Peek \n4.Display \n5.Delete Stack");
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
					push(S,x);
					printf("\n Element Pushed ");
					display(S);
					break;
				}
			case 2:
				{
					x=pop(S);
					if(x==INT_MIN)
					{
					printf("\nStack Underflow");
					break;
					}
					printf("%d ",x);
					printf("\n Element Poped ");
					display(S);
					break;
				}
			case 3:
				{
					x=peek(S);
					if(x==INT_MIN)
					{
					printf("\nStack Underflow");
					break;
				}
					printf("%d ",x);
					printf("\n Element Peeked ");
					break;
					
				}
			case 4:
				{
					display(S);
					break;
				}
			/*case 5:
				{
					delete();
					printf("\n Stack Deleted");
					exit(0);
				}*/
		}
	}
}
struct stack *createstack()
{
	struct stack *S=(struct stack *)malloc(sizeof(struct stack));
	S->top=NULL;
	return S;
	
}
void push(struct stack *S,int x)
{
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	temp->data=x;
	temp->next=S->top;
	S->top=temp;
}
int pop(struct stack *S)
{
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	int x;
	if(S->top==NULL)
	{
		return INT_MIN;
	}
	temp=S->top;
	x=S->top->data;
	S->top=S->top->next;
	free(temp);
	return x;
}
int peek(struct stack *S)
{
	int x;
	if(Isstackempty(S))
	{
		return INT_MIN;
	}
	x=S->top->data;
	return x;
}
void display(struct stack *S)
{
	struct node *head=S->top;
	while(head)
	{
		printf("\t %d \n ",head->data);
		head=head->next;
	}
}
void delete(struct stack *S)
{
	struct node *head=S->top,*temp;
	
	while(head->next=NULL)
	{
		temp=head->next;
		head->next=temp->next;
		free(temp);
	}
	free(head);
}
int Isstackempty(struct stack *S)
{
	return S->top==NULL;
}
