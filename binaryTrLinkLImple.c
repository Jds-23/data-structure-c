#include "stdio.h"
#include "malloc.h"
struct node{
	int data;
	struct node *left;
	struct node *right;
};
struct node *createTree(int);
void preOrderDisplay(struct node *root);
void postOrderDisplay(struct node *root);
void inOrderDisplay(struct node *root);

main(){
	struct node *root,*temp,*newNode;
	int data;
	printf("Enter first node :");
	scanf("%d",&data);
	root=createTree(data);
	printf("\nPre-Order Display\n");
	preOrderDisplay(root);
	printf("\nPost-Order Display\n");
	postOrderDisplay(root);
	printf("\nIn-Order Display\n");
	inOrderDisplay(root);
}

void preOrderDisplay(struct node *root){
	
	printf("%d ",root->data);
	
	if(root->left!=NULL)
	preOrderDisplay(root->left);
	
	if(root->right!=NULL)
	preOrderDisplay(root->right);
	
}

void postOrderDisplay(struct node *root){
	
	if(root->left!=NULL)
	postOrderDisplay(root->left);
	if(root->right!=NULL)
	postOrderDisplay(root->right);
	
	
	printf("%d ",root->data);
}


void inOrderDisplay(struct node *root){
	
	if(root->left!=NULL)
	inOrderDisplay(root->left);
	
	printf("%d ",root->data);
	
	if(root->right!=NULL)
	inOrderDisplay(root->right);
}


struct node *createTree(int data){
	int leftData,rightData;
	struct node *newNode;
	
	if(data==-1){
		return NULL;
	}
	
	newNode=(struct node *)malloc(sizeof(struct node));
	newNode->data=data;
	
	printf("Enter left child & right child  of '%d' :",data);
	scanf("%d %d",&leftData,&rightData);
	newNode->left=createTree(leftData);

	newNode->right=createTree(rightData);	
	
	return newNode;
}
