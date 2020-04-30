#include<stdio.h>
#include<stdlib.h>

struct BTNode{
	
	struct BTNode* left;
	struct BTNode* right;
	int info;
};

struct BTNode* createNode(int data){
	
	struct BTNode* temp;
	temp=(struct BTNode*)malloc(sizeof(struct BTNode));
	temp->left=NULL;
	temp->right=NULL;
	temp->info=data;
	return temp;
}

void createBinaryTree(struct BTNode** r){
	
	*r=createNode(45);
	(*r)->left=createNode(22);
	(*r)->right=createNode(77);
	(*r)->left->left=createNode(11);
	(*r)->left->right=createNode(30);
	(*r)->right->right=createNode(90);
}

void inOrder(struct BTNode* r){
	
	if(r!=NULL){
	   inOrder(r->left);
	   printf("%d ",r->info);
	   inOrder(r->right);
     }
}

void preOrder(struct BTNode* r){
	
	if(r!=NULL){
		printf("%d ",r->info);
		preOrder(r->left);
		preOrder(r->right);
	}
}

void postOrder(struct BTNode* r){
	
	if(r!=NULL){
		postOrder(r->left);
		postOrder(r->right);
		printf("%d ",r->info);
	}
}

int main(){
	
	struct BTNode* root;
	root=NULL;
	createBinaryTree(&root);
	inOrder(root);
	printf("\n");
	preOrder(root);
	printf("\n");
	postOrder(root);
}
