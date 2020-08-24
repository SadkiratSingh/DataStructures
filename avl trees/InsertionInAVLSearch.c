//An empty binary tree is an AVL Tree//
//A non-empty binary tree is an AVL Tree if the two subtrees of each node are AVL trees and balance-factor of each node is 0,1 or-1.//
//An AVL tree is a balanced binary tree//
//A AVL Search Tree is Binary Search Tree satisfying above properties of AVL Tree//

#include<stdio.h>
#include<stdlib.h>

struct AVLNode{
	
	struct AVLNode* left;
	struct AVLNode* right;
	int info;
};

int max(int a,int b){
	
	if(a>=b){
		return a;
	}
	else{
		return b;
	}
}

int height(struct AVLNode* r){
	
	if(r){
		
		int h=1;
		int h_left=height(r->left);
		int h_right=height(r->right);
		h=h+max(h_left,h_right);
		return h;
	}
	else{
		return 0;
	}
}


int get_bal(struct AVLNode* r){
	
	int bal;
	bal=height(r->left)-height(r->right);
	return bal;
}

struct AVLNode* rrRotate(struct AVLNode* A,struct AVLNode* B){
	
	struct AVLNode* temp;
	temp=B->left;
	B->left=A;
	A->right=temp;
	return B;
}

struct AVLNode* llRotate(struct AVLNode* A,struct AVLNode* B){
	struct AVLNode* temp;
	temp=B->right;
	B->right=A;
	A->left=temp;
	return B;
}

struct AVLNode* rlRotate(struct AVLNode* A,struct AVLNode* B){
	
	A->right=llRotate(B,B->left);
	A=rrRotate(A,A->right);
	return A;
}

struct AVLNode* lrRotate(struct AVLNode* A,struct AVLNode* B){
	
	A->left=rrRotate(B,B->right);
	A=llRotate(A,A->left);
	return A;
	
}

struct AVLNode* createNode(int data){
	
	struct AVLNode* temp;
	temp=(struct AVLNode*)malloc(sizeof(struct AVLNode));
	temp->left=NULL;
	temp->right=NULL;
	temp->info=data;
	return temp;
}

struct AVLNode* insert(struct AVLNode* r,int data){
	
	if(r!=NULL){
		if(data>r->info){
			r->right=insert(r->right,data);
		}
		else{
			r->left=insert(r->left,data);
		}
		
		int balance=get_bal(r);
		
		if(balance<-1 && get_bal(r->right)<=0){
		  
			r=rrRotate(r,r->right);
			return r;
		}
		else if(balance>1 && get_bal(r->left)>=0){ 
		
			r=llRotate(r,r->left);
			return r;
		}
		else if(balance<-1 && get_bal(r->right)>0){ 
		     r=rlRotate(r,r->right);
		     return r;
		}
		
		else if(balance>1 && get_bal(r->left)<0){                          
			r=lrRotate(r,r->left);
			return r;
		}
		
		else{
			return r;
		}
	}
	
	else{
		r=createNode(data);
		return r;
	}
}

void inOrder(struct AVLNode* r){
	
	if(r){
	inOrder(r->left);
	printf("%d ",r->info);
	inOrder(r->right);
     }
}

int main(){
	
	struct AVLNode* root;
	root=NULL;
	root=insert(root,5);
	root=insert(root,7);
	root=insert(root,19);
	root=insert(root,12);
	root=insert(root,10);
	root=insert(root,15);
	root=insert(root,18);
	root=insert(root,20);
	root=insert(root,25);
	root=insert(root,23);
	inOrder(root);
}
