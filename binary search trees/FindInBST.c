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
	temp->info=data;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}

void createBST(struct BSTNode** r)
{
	*r=createNode(25);
	(*r)->left=createNode(12);
	(*r)->right=createNode(35);
	(*r)->left->left=createNode(4);
	(*r)->left->right=createNode(15);
	(*r)->right->left=createNode(30);
	(*r)->right->right=createNode(40);
}

void bstFind(struct BSTNode* r,int data){
	
	if(r!=NULL){
	if(r->info==data){
		printf("item found");
	}
	else if(data<r->info){
		bstFind(r->left,data);
	}
	else{
		bstFind(r->right,data);
	}
     }
	else{
		printf("item not found");
	}

}

int main(){
	
	struct BSTNode* root;
	root=NULL;
	createBST(&root);
	bstFind(root,25);
}
