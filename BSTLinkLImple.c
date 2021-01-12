#include "stdio.h"
#include "malloc.h"
#include "stdlib.h"

struct node{
	int data;
	struct node *left,*right;
};

struct node *newNode(int data);
void inOrderDisplay(struct node *root);
struct node *insert(struct node *start,int data);
void preOrderDisplay(struct node *root);
struct node *deleteNode(struct node *start,int data);

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
				printf("\nEnter a number: ");
				scanf("%d",&data);
				root=deleteNode(root,data);
				printf("\nAfter Deletion In-Order Display\n");
				inOrderDisplay(root);
				
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

struct node *insert(struct node *start,int data){
	
	if(start==NULL)
	return newNode(data);
	
	if(start->data>data)
	start->left= insert(start->left,data);
	
	if(start->data<data)
	start->right= insert(start->right,data);
	
	else
	return start;
	
	return start;
}

struct node *deleteNode(struct node *start,int data){
	struct node *temp;
	
	if(start==NULL){
		printf("Element not in treee");
		return NULL;
	}
	
	
	if(start->data>data)
	start->left= deleteNode(start->left,data);
	
	else if(start->data<data)
	start->right= deleteNode(start->right,data);
	
	else{
		if(start->left==NULL){
			temp=start->right;
			free(start);
			return temp; 
		}
		else if(start->right==NULL){
			temp=start->right;
			free(start);
			return temp; 
		}
		else{
			start->data=minValueNode(start->right);
			start->right=deleteNode(start->right,start->data);
		}
	}
	return start;
}
int minValueNode(struct node *root){
	if(root==NULL)
	return 0;
	if(root->left==NULL)
	return root->data;
	else{
		return minValueNode(root->left);
	}
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
	
	printf("%d ",root->data);
	
	if(root->right!=NULL)
	inOrderDisplay(root->right);
}

struct node *newNode(int data){
	struct node *n=(struct node *)malloc(sizeof(struct node));
	n->data=data;
	n->left=n->right=NULL;
	return n;
} 
