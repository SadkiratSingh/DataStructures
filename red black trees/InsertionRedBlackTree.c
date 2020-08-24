#include<stdio.h>
#include<stdlib.h>

struct RBNode{
	
	struct RBNode* left;
	struct RBNode* right;
	struct RBNode* parent;
	int info;
	char color;
};

struct RBNode* createNode(int data){
	
	struct RBNode* temp=(struct RBNode*)malloc(sizeof(struct RBNode));
	temp->left=NULL;
	temp->right=NULL;
	temp->parent=NULL;
	temp->info=data;
	temp->color='R';
}

void swap_col(struct RBNode* g,struct RBNode* p){
	
	char c=g->color;
	g->color=p->color;
	p->color=c;
}

struct RBNode* leftRotate(struct RBNode* root,struct RBNode* g){
	
	struct RBNode* p=g->right;
	struct RBNode* temp=p->left;
	
	p->left=g;
	g->right=temp;
	if(temp){
		temp->parent=g;
	}
	p->parent=g->parent;
	if(g->parent==NULL){
		root=p;
	}
	else if(g==g->parent->right){
		g->parent->right=p;
	}
	else{
		g->parent->left=p;
	}
	g->parent=p;
	return root;
	
}

struct RBNode* rightRotate(struct RBNode* root,struct RBNode* g){
	
	struct RBNode* p=g->left;
	struct RBNode* temp=p->right;
	
	p->right=g;
	g->left=temp;
	if(temp){
		temp->parent=g;
	}
	p->parent=g->parent;
	if(g->parent==NULL){
		root=p;
	}
	else if(g==g->parent->right){
		g->parent->right=p;
	}
	else{
		g->parent->left=p;
	}
	g->parent=p;
	return root;
}

struct RBNode* BSTInsert(struct RBNode* root,struct RBNode* current){
	
	if(root){
		
		if(current->info>root->info){
			
			root->right=BSTInsert(root->right,current);
			root->right->parent=root;
			return root;
		}
		else{
			root->left=BSTInsert(root->left,current);
			root->left->parent=root;
			return root;
		}
	}
	else{
		
		root=current;
		return root;
	}
}

struct RBNode* undoViolation(struct RBNode* root,struct RBNode* curr){
	
	struct RBNode* par=curr->parent;
	struct RBNode* g_parent=NULL;
	struct RBNode* uncle=NULL;
	
	if(!(par)){
		curr->color='B';
		return root;
	}
	else if(par->color=='B'){
		return root;
	}
	else{
		g_parent=par->parent;
		if(par==g_parent->right){
			
			uncle=g_parent->left;
			
			if(!(uncle) || uncle->color=='B'){
				
				if(curr==par->right){
					root=leftRotate(root,g_parent);
					swap_col(g_parent,par);
					return root;
				}
				else{
					root=rightRotate(root,par);
					root=leftRotate(root,g_parent);
					swap_col(g_parent,curr);
					return root;
				}
				
			}
			else{
				uncle->color='B';
				par->color='B';
				g_parent->color='R';
				curr=g_parent;
				root=undoViolation(root,curr);
				return root;
			}
		}
		else{
			uncle=g_parent->right;
			
			if(!(uncle)||uncle->color=='B'){
				
				if(curr==par->left){
					root=rightRotate(root,g_parent);
					swap_col(g_parent,par);
					return root;
				}
				else{
					root=leftRotate(root,par);
					root=rightRotate(root,g_parent);
					swap_col(g_parent,par);
					return root;
				}
			}
			else{
				uncle->color='B';
				par->color='B';
				g_parent->color='R';
				curr=g_parent;
				root=undoViolation(root,curr);
				return root;
			}
		}
	}
	
}

struct RBNode* insertion(struct RBNode* root,int data){
	
	struct RBNode* x=createNode(data);
	root=BSTInsert(root,x);
	root=undoViolation(root,x);
	return root;
}

void printTree(struct RBNode* root){
	if(root){
		printTree(root->left);
		printf("%d->%c ",root->info,root->color);
		printTree(root->right);
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
	printTree(root);
}
