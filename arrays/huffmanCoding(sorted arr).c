#include<stdio.h>
#include<stdlib.h>

struct node{
	
	struct node* left;
	struct node* right;
	int freq;
	char data;
};

struct Queue{
	
	struct node** array;
	int capacity;
	int front;
	int rear;
};

struct node* createNode(char d,int f){
	
	struct node* temp=(struct node*)(malloc(sizeof(struct node)));
	temp->data=d;
	temp->freq=f;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}

struct Queue* createQ(int cap){
	
	struct Queue* temp=(struct Queue*)malloc(sizeof(struct Queue));
	temp->capacity=cap;
	temp->front=-1;
	temp->rear=-1;
	temp->array=(struct node**)malloc(temp->capacity*sizeof(struct node*));
	return temp;
}



int isFullQueue(struct Queue* Q){
	
	if(Q->rear==Q->capacity-1 && Q->front==Q->rear+1){
		return 1;
	}
	else{
		return 0;
	}
}

int isEmptyQueue(struct Queue* Q){
	
	if(Q->front==-1){
		return 1;
	}
	else{
		return 0;
	}
}


int queueSize(struct Queue* Q){
	 
	if(Q->front==-1){
		return 0;
	}
	if(Q->rear>=Q->front){
		return(Q->rear-Q->front+1);
	}
	else{
		return(Q->capacity-(Q->front-Q->rear)+1);
	}
}

void enQueue(struct Queue* Q,struct node* t){
	
	if(!isFullQueue(Q)){
		
		if(Q->front==-1){
			Q->front=Q->rear=0;
			Q->array[Q->rear]=t;
		}
		else if(Q->rear==Q->capacity-1){
			Q->rear=0;
			Q->rear++;
			Q->array[Q->rear]=t;
		}
		else{
			Q->rear++;
			Q->array[Q->rear]=t;
		}
	}
}

struct node* deQueue(struct Queue* Q){
	
	if(!isEmptyQueue(Q)){
		
		struct node* item;
		if(Q->front==Q->rear){
			
			item=Q->array[Q->front];
			Q->array[Q->front]=NULL;
			Q->front=Q->rear=-1;
			return item;
		}
		
		else if(Q->front==Q->capacity-1){
			
			item=Q->array[Q->front];
			Q->array[Q->front]=NULL;
			Q->front=0;
			return item;
		}
		else{
			
			item=Q->array[Q->front];
			Q->array[Q->front]=NULL;
			Q->front++;
			return item;
		}
	}
	else{
		return NULL;
	}
}

struct node* min(struct Queue* Q1,struct Queue* Q2){
	
	if(!isEmptyQueue(Q1) && !isEmptyQueue(Q2)){
		
		if(Q1->array[Q1->front]->freq<Q2->array[Q2->front]->freq){
			return(deQueue(Q1));
		}
		else{
			return(deQueue(Q2));
		}
	}
	else{
		if(isEmptyQueue(Q1)){
			return(deQueue(Q2));
		}
		else{
			return(deQueue(Q1));
		}
	}
}

struct Queue* buildNodesAndQueue(char* A,int* F,int n){
	
	struct Queue* first=createQ(n);
	int i;
	for(i=0;i<n;i++){
		enQueue(first,createNode(A[i],F[i]));
	}
	return first;
}

struct node* createHuffmanTree(char* A,int* F,int n){
	
	struct Queue* queue1=buildNodesAndQueue(A,F,n);
	struct Queue* queue2=createQ(n);
	struct node* m1,*m2,*temp;
	
	while(queueSize(queue2)>1 || !isEmptyQueue(queue1) ){
		
		m1=min(queue1,queue2);
		m2=min(queue1,queue2);
		temp=createNode('\0',m1->freq+m2->freq);
		temp->left=m1;
		temp->right=m2;
		enQueue(queue2,temp);
	}
	return(deQueue(queue2));
	
}

void printHuffmanCodes(struct node* root,int* C,int t){
	
	if(root){
		
		t++;
		if(root->left){
			C[t]='0';
			printHuffmanCodes(root->left,C,t);
		}
	     if(root->right){
	     	C[t]='1';
	     	printHuffmanCodes(root->right,C,t);
		}
		if(!root->left && !root->right){
		int i=0;
		printf("%c-->",root->data);
		while(i<t){
			printf("%c",C[i]);
			i++;
		}
		printf("\n");
	}
		
	}
	
}

void huffmanCodes(char* A,int* F,int n){
	
	struct node* root=createHuffmanTree(A,F,n);
	int code[100];
	int top=-1;
	printHuffmanCodes(root,code,top);
}

int main(){
	
	char arr[]={'a','b','c','d','e','f'};
	int freq[]={5,9,12,13,16,45};
	int n=sizeof(arr)/sizeof(char);
	huffmanCodes(arr,freq,n);
	
}
