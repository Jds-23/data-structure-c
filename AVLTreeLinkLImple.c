#include "stdio.h"
#include "malloc.h"
#include "stdlib.h"

struct node{
	int data,height;
	struct node *left,*right;
};
void preOrderDisplay(struct node *root);
struct node *newNode(int data);
void inOrderDisplay(struct node *root);
struct node *insert(struct node *start,int data);

void main(){
	struct node *root=NULL;
	int c,data;
	while(1){
		printf("\nEnter Your Choice:\n0.To Exit\n1.To Insert\n2.To Delete\n3.To Display:");
		scanf("%d",&c);
		switch(c){
			case 0:{
				exit(0);
			}
			case 1:{
				printf("\nEnter a number: ");
				scanf("%d",&data);
				root=insert(root,data);
				break;
			}
			case 2:{
				printf("\nNot availble: ");
				
				break;
			}
			case 3:{
				printf("\nIn-Order Display\n");
				inOrderDisplay(root);
				printf("\nPre-Order Display\n");
				preOrderDisplay(root);
				break;
			}
			default:{
				printf("\nWrong Input ");
				break;
			}				
		}
	}
}


struct node *rightRotation(struct node *z){
	struct node *y;
	printf("Right Rotating %d",z->data);
	y=z->left;
	z->left=y->right;
	y->right=z;
	
	z->height=max(height(z->left),height(z->right));
	y->height=max(height(y->left),height(y->right));
	
	return y;
}


struct node *leftRotation(struct node *z){
	struct node *y;
	printf("Left Rotating %d",z->data);
	y=z->right;
	z->right=y->left;
	y->left=z;
	
	z->height=max(height(z->left),height(z->right));
	y->height=max(height(y->left),height(y->right));
	
	return y;
}


struct node *insert(struct node *start,int data){
	
	int balance;
	if(start==NULL)
	return newNode(data);
	
	if(start->data>data)
	start->left= insert(start->left,data);
	
	if(start->data<data)
	start->right= insert(start->right,data);
	
	else
	return start;
	
	start->height=1+(max(height(start->left),height(start->right)));
	
	balance=getBalance(start);
	
	//Left Left Case 
	if(balance>1&&start->left->data>data)
	return rightRotation(start);
	
	//Left Right Case
	if(balance>1&&start->left->data<data)
	{
		leftRotation(start->left);
		return rightRotation(start);	
	}
	
	//Right Right Case 
	if(balance<-1&&start->right->data<data)
	return leftRotation(start);
	
	//Right Left Case
	if(balance<-1&&start->right->data>data)
	{
		rightRotation(start->left);
		return leftRotation(start);
	}
	
	
	return start;
}
void preOrderDisplay(struct node *root){
	
	printf("%d ",root->data);
	
	if(root->left!=NULL)
	preOrderDisplay(root->left);
	
	if(root->right!=NULL)
	preOrderDisplay(root->right);
	
}

void inOrderDisplay(struct node *root){
	
	if(root->left!=NULL)
	inOrderDisplay(root->left);
	
	printf("%d (%d) ",root->data,getBalance(root));
	
	if(root->right!=NULL)
	inOrderDisplay(root->right);
}
int getBalance(struct node *root){
	if(root==NULL)
	return 0;
	return (height(root->left)-height(root->right));
}
int max(int a,int b){
	return (a>b)?a:b;
}
int height(struct node *root){
	if(root==NULL)
	return 0;
	
	return root->height;
}
struct node *newNode(int data){
	struct node *n=(struct node *)malloc(sizeof(struct node));
	n->data=data;
	n->left=n->right=NULL;
	n->height=1;
	return n;
} 
