//Any Improvements are welcome//

#include<stdio.h>
#include<stdlib.h>
#include "InsertionRBTree.h"

void leftRotateD(struct RBNode** root,struct RBNode* pt){
	
	struct RBNode* pt_rt=pt->right;
	struct RBNode* temp=pt_rt->left;
	
	pt_rt->left=pt;
	pt->right=temp;
	if(temp){
		temp->parent=pt;
	}
	pt_rt->parent=pt->parent;
	if(pt->parent==NULL){
		*root=pt_rt;
	}
	else if(pt==pt->parent->right){
		pt->parent->right=pt_rt;
	}
	else{
		pt->parent->left=pt_rt;
	}
	pt->parent=pt_rt;
}

void rightRotateD(struct RBNode** root,struct RBNode* pt){
	
	struct RBNode* pt_lt=pt->left;
	struct RBNode* temp=pt_lt->right;
	
	pt_lt->right=pt;
	pt->left=temp;
	if(temp){
		temp->parent=pt;
	}
	pt_lt->parent=pt->parent;
	if(pt->parent==NULL){
		*root=pt_lt;
	}
	else if(pt==pt->parent->right){
		pt->parent->right=pt_lt;
	}
	else{
		pt->parent->left=pt_lt;
	}
	pt->parent=pt_lt;
}


struct RBNode* nodeToDelete(struct RBNode* root,int data){
	
	if(root){
		if(data>root->info){
			return(nodeToDelete(root->right,data));
		}
		else if(data<root->info){
			return(nodeToDelete(root->left,data));
		}
		else{
			struct RBNode* temp;
			
			if(root->right && root->left){
				temp=root->right;
				while(temp->left){
					temp=temp->left;
				}
				root->info=temp->info;
				return(nodeToDelete(root->right,temp->info));
			}
			else{
				return root;
			}
		}
	}
	else{
		return NULL;
	}
}

struct RBNode* replacedNode(struct RBNode** root,struct RBNode* v){
	
	     struct RBNode* u;
		
		if(!v->left || !v->right){

			if(!v->left){
			     u=v->right;
		     }
		     else{
		     	u=v->left;
			}
			if(u){
				u->parent=v->parent;
			}
			if(!v->parent){
				*(root)=u;
			}
			else if(v==v->parent->left){
				v->parent->left=u;
			}
			else{
				v->parent->right=u;
			}
			free(v);
			return u;
		}
}

void toSingleBlack(struct RBNode** root,struct RBNode* u,struct RBNode* vu_par){
	
	if(!u && !vu_par){
		return;
	}
	else if(u && !vu_par){
		return;
	}
	else{
		struct RBNode* s;
		struct RBNode* r;
		struct RBNode* par_s;
		
		if((!u && !vu_par->left) || (u && u==vu_par->left)){
			s=vu_par->right;
			par_s=s->parent;
			if(s->color=='B'){
				if(s->right && s->right->color=='R'){
					
					r=s->right;
					leftRotateD(root,par_s);
					if(par_s->color=='B'){
					     r->color='B';
				     }
				}
				else if(s->left && s->left->color=='R'){
					
					r=s->left;
					rightRotateD(root,s);
					swap_col(r,s);
					leftRotateD(root,par_s);
					if(par_s->color=='B'){
					     s->color='B';
				     }
				}
				else{
					s->color='R';
					if(par_s->color=='B'){
						toSingleBlack(root,par_s,par_s->parent);
					}
					else{
						par_s->color='B';
					}
				}
			}
			else{
				leftRotateD(root,par_s);
				swap_col(par_s,s);
				toSingleBlack(root,u,vu_par);
			}
		}
		else{
			s=vu_par->left;
			par_s=s->parent;
			if(s->color=='B'){
				if(s->left && s->left->color=='R'){
					r=s->left;
					rightRotateD(root,par_s);
					if(par_s->color=='B'){
						r->color='B';
					}
				}
				else if(s->right && s->right->color=='R'){
					r=s->right;
					leftRotateD(root,s);
					swap_col(r,s);
					rightRotateD(root,par_s);
					if(par_s->color=='B'){
						s->color='B';
					}
				}
				else{
					s->color='R';
					if(par_s->color=='B'){
						toSingleBlack(root,par_s,par_s->parent);
					}
					else{
						par_s->color='B';
					}
				}
			}
			else{
				rightRotateD(root,par_s);
				swap_col(par_s,s);
				toSingleBlack(root,u,vu_par);
			}
		}
	}
}

void deletion(struct RBNode** root,int data){
	
	struct RBNode* v=nodeToDelete(*root,data);
	struct RBNode* u=NULL;
	if(v){
		char v_col;
		struct RBNode* vu_par;
		v_col=v->color;
		vu_par=v->parent;
		u=replacedNode(root,v);
		
		if(!u || u->color=='B'){
			if(v_col=='B'){
				toSingleBlack(root,u,vu_par);
			}
		}
		else{
			u->color='B';
		}
	}
	else{
		printf("data item not in the tree");
	}
}

int main(){
	
	struct RBNode* root=NULL;
	root=insertion(root,50);
	root=insertion(root,60);
	root=insertion(root,70);
	root=insertion(root,40);
	root=insertion(root,55);
	root=insertion(root,30);	
	root=insertion(root,57);	
	root=insertion(root,45);	
	root=insertion(root,20);
     deletion(&root,40);
     deletion(&root,30);
     deletion(&root,45);
     deletion(&root,20);
	printTree(root);
}
