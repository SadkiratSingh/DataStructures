//complexity of huffman Coding is O(nlogn)//

#include<stdio.h>
#include<stdlib.h>

struct node{
	
	struct node* left;
	struct node* right;
	int freq;
	char data;
};

struct heapControl{
	struct node** array;
	int capacity;
	int top;
};

struct heapControl* createHeapControl(int cap){
	
	struct heapControl* temp;
	temp=(struct heapControl*)malloc(sizeof(struct heapControl));
	temp->capacity=cap;
	temp->array=(struct node**)malloc((temp->capacity)*sizeof(struct node*));
	temp->top=-1;
	return temp;
}

struct node* createNode(char d,int f){
	
	struct node* temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->left=NULL;
	temp->right=NULL;
	temp->data=d;
	temp->freq=f;
	return temp;
}

void swap(struct heapControl* H,int a,int b){
	
	struct node* temp;
	temp=H->array[a];
	H->array[a]=H->array[b];
	H->array[b]=temp;
}

void heapify(struct heapControl* H,int i){
	
	int l=2*i+1;
	int r=2*i+2;
	int min=i;
	if(l<=H->top && H->array[l]->freq<H->array[min]->freq){
		min=l;
	}
	if(r<=H->top && H->array[r]->freq<H->array[min]->freq){
		min=r;
	}
	if(min!=i){
		swap(H,i,min);
		heapify(H,min);
	}
}

void heapifyOnInsert(struct heapControl* H,int i){
	
	int p=(i-1)/2;
	if(p>=0 && H->array[i]->freq<H->array[p]->freq){
		swap(H,i,p);
		heapifyOnInsert(H,p);
	}
}

void insert(struct heapControl* H,struct node* t){
	
	if(H->top<=H->capacity-1){
		H->top++;
		H->array[H->top]=t;
		heapifyOnInsert(H,H->top);
	}
}

void buildMinHeap(struct heapControl* H){
	
	int j;
	for(j=((H->top)-1)/2;j>=0;j--){
		heapify(H,j);
	}
}

struct heapControl* createNodesAndMinHeap(char* A,int* F,int n){
	
	struct heapControl* H=createHeapControl(n);
	int i;
	for(i=0;i<n;i++){
		H->top++;
		H->array[H->top]=createNode(A[i],F[i]);
     }
     buildMinHeap(H);
	return H;
}

struct node* extract(struct heapControl* H){
	
	struct node* item=H->array[0];
	H->array[0]=H->array[H->top];
	H->array[H->top]=NULL;
	H->top--;
	if(H->top>=0){
		heapify(H,0);
	}
	return item;
}

void printMinHeap(struct heapControl* H){
	
	int i;
	for(i=0;i<=H->top;i++){
		printf("%c->",H->array[i]->data);
		printf("%d ",H->array[i]->freq);
		printf("\t");
	}
}

void printTree(struct node* root){
	if(root){
		printTree(root->left);
		printf("%d ",root->freq);
		printTree(root->right);
	}
}

struct node* createHuffmanTree(char* A,int* F,int n){
	
	struct heapControl* MinHeap;
	MinHeap=createNodesAndMinHeap(A,F,n);
	struct node* m1,*m2,*temp;
	
	while(MinHeap->top>0){
		
	m1=extract(MinHeap);
	m2=extract(MinHeap);
	
	int sum=(m1->freq)+(m2->freq);
	temp=createNode('\0',sum);
	temp->left=m1;
	temp->right=m2;
	insert(MinHeap,temp);
}
     return(extract(MinHeap));

	
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
	
	char ary[6]={'a', 'b', 'c', 'd', 'e', 'f'};
	int freq[6]={ 5, 9, 12, 13, 16, 45};
	int n=sizeof(ary)/sizeof(char);
	huffmanCodes(ary,freq,n);
}
