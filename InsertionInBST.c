#include<stdio.h>
#include<stdlib.h>

struct BSTNode{
	
	struct BSTNode* left;
	struct BSTNode* right;
	int info;
};


struct BSTNode* createNode(int data){
	
	struct BSTNode* temp;
	temp=(struct BSTNode*)malloc(sizeof(struct BSTNode));
	temp->right=NULL;
	temp->left=NULL;
	temp->info=data;
	return temp;
}

struct BSTNode* insertInBST(struct BSTNode* r,int data){
	
	if(r!=NULL){
		
	if(data>r->info){
		r->right=insertInBST(r->right,data);
		return r;
	}
	else if(data<r->info){
		r->left=insertInBST(r->left,data);
		return r;
	}
     }
     else{
     	r=createNode(data);
     	return r;
	}
}

void preOrder(struct BSTNode* r){
	
	if(r!=NULL){
		printf("%d ",r->info);
		preOrder(r->left);
		preOrder(r->right);
	}
}

int main(){
	
	struct BSTNode* root;
	root=NULL;
	root=insertInBST(root,40);
	root=insertInBST(root,60);
	root=insertInBST(root,50);
	root=insertInBST(root,33);
	root=insertInBST(root,55);
	root=insertInBST(root,11);
	root=insertInBST(root,20);
	root=insertInBST(root,17);
     root=insertInBST(root,70);
	preOrder(root);
}

