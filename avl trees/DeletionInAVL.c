#include<stdio.h>
#include<stdlib.h>
#include "InsertionInAVL.h"

struct AVLNode* deletion(struct AVLNode* r,int data){
	
	if(r){
		if(data>r->info){
			r->right=deletion(r->right,data);
		}
		else if(data<r->info){
			r->left=deletion(r->left,data);
		}
		else if(data==r->info){
			
			struct AVLNode* temp;
			
			if(!(r->right)){
				
				temp=r;
				r=r->left;
				free(temp);
				return r;
			}
			else if(!(r->left)){
				temp=r;
				r=r->right;
				free(temp);
				return r;
			}
			else if(r->right && r->left){
				temp=r->right;
				while(temp->left!=NULL){
					temp=temp->left;
				}
				r->info=temp->info;
				deletion(r->right,temp->info);
				return r;
			}
		}
		int balance=get_bal(r);
		
		if(balance>1 && get_bal(r->left)>=0){
			
			r=llRotate(r,r->left);
			return r;
		}
		else if(balance>1 && get_bal(r->left)<0){
			
			r=lrRotate(r,r->left);
			return r;
		}
		else if(balance<-1 && get_bal(r->right)<=0){
			
			r=rrRotate(r,r->right);
			return r;
		}
		else if(balance<-1 && get_bal(r->right)>0){
			r=rlRotate(r,r->right);
			return r;
		}
		else{
			return r;
		}
		
	}
	else{
		return NULL;
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
	root=insert(root,44);
	root=insert(root,22);
	root=insert(root,48);
	root=insert(root,18);
	root=insert(root,28);
	root=insert(root,23);
	root=insert(root,29);
	root=insert(root,52);
	root=deletion(root,52);
	inOrder(root);
}
