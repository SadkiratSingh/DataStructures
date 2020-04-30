#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node{
	
	struct node* link;
	int info;
};

struct address{
	struct node* parent;
	struct node* current;
};

struct node* createNode(int data);

struct node* insertAtStart(struct node* P,int data);
struct node* insertAtLast(struct node* P,int data);
void insertAfter(struct node* P,int data);

int deleteItemFromLast(struct node* P);
struct node deleteItemFromStart(struct node* P);
struct node deleteCurrentItem(struct node* P,int c_data);

struct address search(struct node* P,int data);
int countItems(struct node* P);
int getFirstItem(struct node* P);
void viewList(struct node* P);

struct node* createNode(int data){
	
	struct node* temp; //temp for temporary node
	temp=(struct node*)malloc(sizeof(struct node));
	temp->info=data;
	temp->link=NULL;
	return temp;
}

struct node* insertAtStart(struct node* P,int data){
	
	struct node* temp;
	temp=createNode(data);
	temp->link=P;
	P=temp;
	return P;
}

struct node* insertAtLast(struct node* P,int data){
	struct node* temp,*T;
	T=P;
	if(T==NULL){
		return(insertAtStart(T,data));
	}
	else{
		temp=createNode(data);
	     while(T->link!=NULL){
		     T=T->link;
	     }
	T->link=temp;
	return P;
}
}

void insertAfter(struct node* P,int data,int c_data){
	
	struct node* temp;
	struct address A;
	A=search(P,c_data);
	
	if(A.current!=NULL){
	   temp=createNode(data);
	   temp->link=A.current->link;
	   A.current->link=temp;
}
	
}

int deleteItemFromLast(struct node* P){
	
	struct node* T,*par=NULL;
	int item;
	T=P;
	if(T==NULL){
		printf("List is empty");
		return -1;
	}
	else{
	while(T->link!=NULL){
		par=T;
		T=T->link;
	}
	item=T->info;
	free(T);
	par->link=NULL;
	return item;
}
}

struct node deleteItemFromStart(struct node* P){
	
	struct node* D;
	int item;
	struct node r;
	D=P;
	if(D==NULL){
		printf("List is empty");
		r={D,-1};
		return r;
	}
	else{
		P=P->link;
		item=D->info;
		free(D);
		r={P,item};
		return r;
	}
}

struct node deleteCurrentItem(struct node* P,int c_data){
	
	struct address A;
	struct node r;
	int item;
	A=search(P,c_data);
	if(A.current!=NULL){
		if(A.parent==NULL){
			return(deleteItemFromStart(P));
	     }
	     else{
		     A.parent->link=A.current->link;
		     item=A.current->info;
		     free(A.current);
		     r={P,item};
		     return r;
	     }
	}
	else{
		r={P,-1};
		return r;
	}
	
}

struct address search(struct node* P,int data){
	
	struct node* T,*par=NULL;
	struct address a;
	T=P;
	while(T!=NULL && T->info!=data){
		     par=T;
			T=T->link;
	}
	if(par==NULL && T==NULL){
			printf("\nlist is empty\n");
			a={par,T};
			return a;
	}
	else if(T==NULL){
		
		printf("\nitem not in the list\n");
		a={par,T};
		return a;
	}
	else{
		a={par,T};
		return a;
	}
}

int countItems(struct node* P){
	
	struct node* T=P;
	int count=0;
	while(T!=NULL){
		count++;
		T=T->link;
	}
	return count;
}

int getFirstItem(struct node* P){
	
	if(P==NULL){
		printf("list is empty");
		return -1;
	}
	else{
	     return(P->info);
     }
}

void viewList(struct node* P){
	
	struct node* T; //T for traversing
	T=P;
	if(T==NULL){
		printf("\nlist is empty\n");
	}
	else{
	while(T!=NULL){
		printf("%d ",T->info);
		T=T->link;
	}
}
}


int main(){
	
	struct node* P=NULL;
	P=insertAtStart(P,20);
	P=insertAtStart(P,10);
	////////////////////
	P=insertAtLast(P,30);
	P=insertAtLast(P,40);
	P=insertAtLast(P,50);
	P=insertAtLast(P,60);
	////////////////////
	insertAfter(P,70,60);
	insertAfter(P,100,50);
	/////////////////////
	//int d1=deleteItemFromLast(P);
	//printf("%d\n",d1);
	/////////////////////
	//struct node a=deleteItemFromStart(P);
	//P=a.link;
	//printf("%d\n",a.info);
	//////////////////////
	//struct node a=deleteCurrentItem(P,200);
	//P=a.link;
	//printf("%d\n",a.info);
	//////////////////////
	printf("%d\n",getFirstItem(P));
	printf("%d\n",countItems(P));
	viewList(P);
}

