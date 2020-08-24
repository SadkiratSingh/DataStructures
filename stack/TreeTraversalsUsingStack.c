#include<stdio.h>
#include<stdlib.h>
struct BTNode{
	
	struct BTNode* left;
	struct BTNode* right;
	int info;
};

#include "BinaryTreeStack.h"

struct BTNode* createNode(int data){
	
	struct BTNode* temp;
	temp=(struct BTNode*)malloc(sizeof(struct BTNode));
	temp->left=NULL;
	temp->right=NULL;
	temp->info=data;
	return temp;
}

void createBinaryTree(struct BTNode** r){
	
	*r=createNode1(45);
	(*r)->left=createNode(22);
	(*r)->right=createNode(77);
	(*r)->left->left=createNode(11);
	(*r)->left->right=createNode(30);
	(*r)->right->right=createNode(90);
}

void preOrder(struct BTNode* r){
	
	struct node* Stack=NULL;
	
	do{
	while(r!=NULL){
		
		printf("%d ",r->info);
		
		if(r->right){
			push(&Stack,r->right);
		}
		r=r->left;
	}
	
	if(Stack!=NULL){
	               
		r=pop(&Stack);  
     }
	
	}while(r!=NULL);
	
}

void inOrder(struct BTNode* r){
	
	struct node* Stack=NULL;
	
	do{
	while(r!=NULL){
		
		if(r->right){
			push(&Stack,r->right);
		}
		push(&Stack,r);
		r=r->left;
	}
	
	r=pop(&Stack);
	printf("%d ",r->info);
	
	if(r->right){
		
		r=pop(&Stack);
	}
	else{
		r=NULL;
	}
	
	}while(Stack!=NULL || r!=NULL);
}

void postOrder(struct BTNode* r){
	
	struct node* Stack=NULL;
	
	do{
	while(r!=NULL){
		
		if(r->right){
			push(&Stack,r->right);
		}
		push(&Stack,r);
		r=r->left;
	}
	r=pop(&Stack);
	
	if(r->right && r->right==peek(&Stack)){
		
		pop(&Stack);
		push(&Stack,r);
		r=r->right;
	}
	else{
		printf("%d ",r->info);
		r=NULL;
	}
	}while(r!=NULL || Stack!=NULL);
}

int main(){
	
	struct BTNode* root;
	root=NULL;
	createBinaryTree(&root);
	preOrder(root);
	printf("\n");
	inOrder(root);
	printf("\n");
	postOrder(root);
}


