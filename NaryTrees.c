#include "stdio.h"
#include "malloc.h"
#include "stdlib.h"
#include "stdbool.h"

struct Node{
    int data;
    struct Node *firstChild;
    struct Node *nextSibling;
    struct Node *parent;
    bool isLocked;
    int noOfLockedDecendent;
    int operation;
};
bool lock(struct Node *node);
bool unLock(struct Node *node);
void addChild(int data,struct Node *parent);
struct Node *createNode(int,struct Node *);
struct Node *searchAddress(int data,struct Node *root);
void preOrderDisplay(struct Node *root);

int main(){
	struct Node *root,*parent,*temp;
	int data,c;
	printf("/nEnter the first element: ");
	scanf("%d",&data);
	root=createNode(data,NULL);
	parent=searchAddress(1,root);
					addChild(2,parent);
					addChild(3,parent);
					addChild(4,parent);
					addChild(5,parent);
					parent=searchAddress(2,root);
					addChild(6,parent);
					addChild(7,parent);
					parent=searchAddress(3,root);
					addChild(8,parent);
					addChild(9,parent);
					parent=searchAddress(4,root);
					addChild(10,parent);
					parent=searchAddress(5,root);
					addChild(11,parent);
					addChild(12,parent);
	while(1){
		printf("\n1.Add Child\n2. Display\n3. Search\n4. To Lock\n5. To UnLock\nEnter choice: ");
		scanf("%d",&c);
					
		switch(c){
			case 1:{
				//printf("\nTo which node do you want to add: ");
				//scanf("%d",&data);
				//parent=searchAddress(data,root);
				//if(parent==NULL){
				//	printf("\nNo Node found");
				//}
				//else{
				//	printf("\nEnter the Data: ");
				//	scanf("%d",&data);
				//}
				
				break;
			}
			case 2:{
				preOrderDisplay(root);
				break;
			}
			case 3:{
				printf("\nTo which node do you want to search: ");
				scanf("%d",&data);
				parent=searchAddress(data,root);
				printf("\nAddress=%d\nData=%d",parent,parent->data);
				break;
			}
			case 4:{
				printf("\nTo which node do you want to Lock: ");
				scanf("%d",&data);
				temp=searchAddress(data,root);
				if(lock(temp)){
					printf("\nTrue");
				}else{
					printf("\nFalse");
				}
				break;
			}
			case 5:{
				printf("\nTo which node do you want to Lock: ");
				scanf("%d",&data);
				temp=searchAddress(data,root);
				if(unLock(temp)){
					printf("\nTrue");
				}else{
					printf("\nFalse");
				}
				break;
			}
		}
	}
}
void addChild(int data,struct Node *parent){
	struct Node *node=createNode(data,parent),*start;
	if(parent->firstChild==NULL){
		parent->firstChild=node;
	}
	else{
		start=parent->firstChild;
		while(start->nextSibling!=NULL){
			start=start->nextSibling;
		}
		start->nextSibling=node;
	}
}
struct Node *createNode(int data,struct Node *parent){
	struct Node *node;
	node=(struct Node *)malloc(sizeof(struct Node));
	node->data=data;
	node->firstChild=NULL;
	node->nextSibling=NULL;
	node->parent=parent;
	node->isLocked=false;
	node->noOfLockedDecendent=0;
	node->operation=0;
	return node;
}
void preOrderDisplay(struct Node *root){
	
	printf("%d ",root->data);
	
	if(root->firstChild!=NULL)
	preOrderDisplay(root->firstChild);
	
	if(root->nextSibling!=NULL)
	preOrderDisplay(root->nextSibling);	
}

struct Node *searchAddress(int data,struct Node *root){
	struct Node *temp;
	
	if(root==NULL)
	return NULL;
	
	if(data==root->data)
	return root; 
	
	temp=searchAddress(data,root->firstChild);
	
	if(temp!=NULL)
	return temp;
	
	temp=searchAddress(data,root->nextSibling);
	
	return temp;
}

bool unLock(struct Node *node){
	struct Node *temp=node;
	if(temp->isLocked==false){//to check if it was locked or not
		return false;
	}
	node->isLocked=false;//unlocking it
	temp=node->parent;
	while(temp!=NULL){
		temp->noOfLockedDecendent--;
		temp=temp->parent;
	}//a loop traversing node's parents decrementing the number of locked decendent of its ancestor by 1 since it is unlocked now
	return true; 
}

  bool lock(struct Node *node){
	struct Node *temp;
	if(node->isLocked==true){//to check if it was locked or not
		return false;
	}
	node->operation+=1;
	node->isLocked=true;//locking the node
	temp=node->parent;
	while(temp!=NULL){
	temp->noOfLockedDecendent++;
	temp=temp->parent;
	}// a loop traversing its parents incrementing the number of locked decendent of its ancestor by 1 since it is locked now
	
	if(node->noOfLockedDecendent>0){
		unLock(node);
		node->operation-=1;
		return false;
	}
	
	temp=node->parent;
	while(temp!=NULL){
		if(temp->isLocked==true){
			unLock(node);
			node->operation-=1;
			return false;
		}
		temp=temp->parent;
	}
	
	if(node->operation!=1){
	    temp=node->parent;	
		while(temp!=NULL){
		temp->noOfLockedDecendent--;
		temp=temp->parent;
		}
		node->operation-=1;	
		return false;
	}
	
	node->operation-=1;
	return true;
}





