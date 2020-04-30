///////////////////////////////Stack using Linked List///////////////////////

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node{
	struct node* next;
	int info;
};

void push(struct node** S,int data);
int pop(struct node** S);
int peek(struct node** S);
void viewStack(struct node** S);
void removeStack(struct node** S);

struct node* createNode(int data){
	
	struct node* temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->info=data;
	temp->next=NULL;
	return temp;
}

void push(struct node** S,int data){
	
	struct node* temp=createNode(data);
	temp->next=*S;
	*S=temp;
}

int pop(struct node** S){
	
	struct node* D;
	int item;
	
	D=*S;
	if(D==NULL){
		printf("underflow!!");
		return -1;
	}
	else{
		*S=D->next;
		 item=D->info;
		 free(D);
		 return item;
	}
}

int peek(struct node** S){
	
	if(*S==NULL){
		printf("Stack is empty");
		return -1;
	}
	else{
		return((*S)->info);
	}
}

void viewStack(struct node** S){
	
	struct node* T;
	T=*S;
	if(T==NULL){
		printf("Stack is empty");
	}
	else{
	while(T!=NULL){
		
		printf("%d ",T->info);
		T=T->next;
	}
}
}

void removeStack(struct node** S){
	
	while(*S!=NULL){
		pop(S);
	}
}

int menu(){
	
	int ch;
	system("cls");
	printf("\n1. Push Element Into The Stack");
	printf("\n2. Pop Element From The Stack");
	printf("\n3. View Top Element");
	printf("\n4. View Stack");
	printf("\n5. Delete Stack");
	printf("\nEnter your choice");
	scanf("%d",&ch);
	return ch;
}

int main(){
	
	struct node* Stack;
	Stack=NULL;
	int item,d;
	while(1){
	switch(menu()){
		
		case 1:
			printf("\nEnter the data");
			scanf("%d",&d);
			push(&Stack,d);
			break;
		
		case 2:
			item=pop(&Stack);
			printf("\n%d",item);
			break;
		
		case 3:
			printf("\n%d",peek(&Stack));
			break;
		
		case 4:
			viewStack(&Stack);
			break;
			
		case 5:
			removeStack(&Stack);
			break;
		
		default:
			printf("Invalid Choice");
	}
	getch();
}
}
