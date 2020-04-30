//inorder traversal of binary search tree arranges the nodes in ascending order//
//inorder successor of a node is the smallest node in the right subtree of the node//

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
	temp->left=NULL;
	temp->right=NULL;
	temp->info=data;
	return temp;
}

struct BSTNode* insert(struct BSTNode* r,int data){
	
	if(r){
		if(data>r->info){
			r->right=insert(r->right,data);
			return r;
		}
		else{
			r->left=insert(r->left,data);
			return r;
		}
	}
	else{
		r=createNode(data);
		return r;
	}
}

struct BSTNode* deletion(struct BSTNode* r,int data){
	
	if(r!=NULL){
		if(data>r->info){
			r->right=deletion(r->right,data);
			return r;
		}
		else if(data<r->info){
			r->left=deletion(r->left,data);
			return r;
		}
		else if(data==r->info){
			
			struct BSTNode* temp;
			
			if(r->left && r->right){
				temp=r->right;
				while(temp->left){
					temp=temp->left;
				}
				r->info=temp->info;
				deletion(r->right,temp->info);
				return r;
			}
			else{
				if(!r->right){
					temp=r;
					r=r->left;
					free(temp);
					return r;
				}
				else{
					temp=r;
					r=r->right;
					free(temp);
					return r;
				}
			}
		}
	}
	else{
		printf("Item not in the tree");
		return NULL;
	}
}

void preOrder(struct BSTNode* r){
	
	if(r){
		printf("%d ",r->info);
		preOrder(r->left);
		preOrder(r->right);
	}
}

int main(){
	
	struct BSTNode* root;
	root=NULL;
	root=insert(root,60);
	root=insert(root,75);
	root=insert(root,66);
	root=insert(root,25);
	root=insert(root,15);
	root=insert(root,50);
	root=insert(root,33);
	root=insert(root,44);
	root=deletion(root,44);
	root=deletion(root,75);
	root=deletion(root,25);
	preOrder(root);
}
