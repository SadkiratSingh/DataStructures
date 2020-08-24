#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct heap{
	
	int* array;
	int top;
	int capacity;
};

struct heap* createHeap(int cap);
void Insertion(struct heap* H,int data);
int DeleteRoot(struct heap* H);

void HeapifyOnInsert(struct heap* H,int t);
void HeapifyOnDelete(struct heap* H,int r);

void swap(struct heap* H,int a,int b);
int max(struct heap* H,int a,int b);
void printHeap(struct heap* H);

void DoubleArray(struct heap* H);
void ShrinkArray(struct heap* H);

void swap(struct heap* H,int a,int b)
{
	int temp;
	temp=H->array[b];
	H->array[b]=H->array[a];
	H->array[a]=temp;
}

int max(struct heap* H,int a,int b)
{
	if(H->array[a]>H->array[b])
	{
	  return a;
     }
	else if(H->array[a]<H->array[b])
	{
	  return b;
     }
	else 
	{
	  return a;
     }
}

void DoubleArray(struct heap* H)
{
	H->capacity=2*H->capacity;
	int* temp_hp=(int*)malloc(H->capacity*sizeof(int));
	int i;
	for(i=0;i<=H->top;i++)
	{
		temp_hp[i]=H->array[i];
	}
	free(H->array);
	H->array=temp_hp;
}

void ShrinkArray(struct heap* H)
{
	H->capacity=H->capacity/2;
	int* temp_hp=(int*)malloc(H->capacity*sizeof(int));
	int i;
	for(i=0;i<=H->top;i++)
	{
		temp_hp[i]=H->array[i];
	}
	free(H->array);
	H->array=temp_hp;
}

struct heap* createHeap(int cap)
{
	struct heap* temp=(struct heap*)malloc(sizeof(struct heap));
	temp->top=-1;
	temp->capacity=cap;
	temp->array=(int*)malloc(temp->capacity*sizeof(int));
	return temp;
}

void HeapifyOnInsert(struct heap* H,int t)
{
	int p=(t-1)/2;
	if(t>0 && H->array[t]>H->array[p])
	{
		swap(H,t,p);
		HeapifyOnInsert(H,p);
	}
}

void HeapifyOnDelete(struct heap* H,int r)
{
	int left=2*r+1;
	int right=2*r+2;
	if(left>H->top && right>H->top)
	{
	   return;
     }
	else if(right>H->top && H->array[r]<=H->array[left])
	{
		swap(H,r,left);
		HeapifyOnDelete(H,left);
	}
	else if(left>H->top && H->array[r]<=H->array[right])
	{
		swap(H,r,right);
		HeapifyOnDelete(H,right);
	}
	else if(H->array[r]<=H->array[right] || H->array[r]<=H->array[left])
	{
		int larger=max(H,left,right);
		swap(H,r,larger);
		HeapifyOnDelete(H,larger);
	}
		
}


void Insertion(struct heap* H,int data)
{
	if(H->top==-1){
	   H->top=0;
	   H->array[H->top]=data;
     }
     
     else if(H->top==H->capacity-1)
     {
     	DoubleArray(H);
     	H->top++;
     	H->array[H->top]=data;
     	HeapifyOnInsert(H,H->top);
	}
	else
	{
		H->top++;
		H->array[H->top]=data;
		HeapifyOnInsert(H,H->top);
	}
}

int DeleteRoot(struct heap* H)
{
	int item,count,i;
	
	if(H->top==-1)
	{
	  printf("Heap is Empty");
     }
	  
	else{
	item=H->array[0];
	H->array[0]=H->array[H->top];
	H->array[H->top]=0;
	H->top--;
	   
	if(H->top>-1){
		HeapifyOnDelete(H,0);
		count=0;
		for(i=0;i<=H->top;i++){
		   count++;
	     }
		if(count==H->capacity/2){
		   ShrinkArray(H);
	     } 
	}
     }
	return item;
}

void printHeap(struct heap* H)
{
	if(H->top==-1)
	{
	  printf("\nHeap is empty");
     }
	else{
		int i;
		for(i=0;i<=H->top;i++)
		{
		   printf("%d ",H->array[i]);
	     } 
	}
}

int menu(){
	
	int c;
	system("cls");
	printf("\n1. Insert An Element Into Heap");
	printf("\n2. Delete Root");
	printf("\n3. View The Status of the Heap");
	printf("\n4. Print Heap");
	printf("\n5. Exit");
	printf("\n\n Enter Your Choice");
	scanf("%d",&c);
	return c;
}


int main()
{
	struct heap* H;
	int info;
	H=createHeap(5);
	while(1){
	switch(menu()){
		case 1:
			printf("\nEnter the info");
			scanf("%d",&info);
			Insertion(H,info);
			break;
		
		case 2:
			DeleteRoot(H);
			break;
		
		
		case 3:
			printf("\nPosition of last element is %d",H->top);
			printf("\nCapacity of Heap is %d",H->capacity);
			printf("\nRoot of Heap is %d",H->array[0]);
			break;
		
		case 4:
			printHeap(H);
			break;
		
		case 5:
			free(H->array);
			free(H);
			exit(0);
			break;
		
		default:
			printf("Invalid Choice");
		
			
	}
	getch();
}
}
