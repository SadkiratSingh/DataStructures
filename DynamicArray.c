#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct DAControl{
	
	int* array;
	int top;
	int capacity;
};

struct DAControl* createArray(int cap);
void Insertion(struct DAControl* D,int data);
void DoubleArray(struct DAControl* D);
int DeletionAtEnd(struct DAControl* D);
int DeletionAtAny(struct DAControl* D,int pos);
void ShrinkArray(struct DAControl* D);
void printArray(struct DAControl* D);

struct DAControl* createArray(int cap)
{
	struct DAControl* temp;
	temp=(struct DAControl*)malloc(sizeof(struct DAControl));
	temp->capacity=cap;
	temp->array=(int*)malloc((temp->capacity)*sizeof(int));
	temp->top=-1;
	return temp;
}

void DoubleArray(struct DAControl* D)
{
	int i;
	int* temp_ary=NULL;
	D->capacity=2*D->capacity;
	temp_ary=(int*)malloc(D->capacity*sizeof(int));
	for(i=0;i<=D->top;i++)
	{
	    temp_ary[i]=D->array[i];
     }
	    
	free(D->array);
	D->array=temp_ary;
	temp_ary=NULL;
	
}

void ShrinkArray(struct DAControl* D)
{
	int* temp_ary=NULL;
	int i;
	D->capacity=D->capacity/2;
	temp_ary=(int*)malloc(D->capacity*sizeof(int));
	for(i=0;i<=D->top;i++)
	{
	    temp_ary[i]=D->array[i];
     }
	free(D->array);
	D->array=temp_ary;
	temp_ary=NULL;
}

void Insertion(struct DAControl* D,int data)
{
	if(D->top==-1){
		D->top=0;
		D->array[D->top]=data;
	}
	else if(D->top==D->capacity-1){
		DoubleArray(D);
		D->top++;
		D->array[D->top]=data;
	}
	else{
		D->top++;
		D->array[D->top]=data;
	}
}

int DeletionAtAny(struct DAControl* D,int pos)
{
	int item,count,k;
	if(D->top==-1){
	   printf("Array is Empty");
     }
	
	else{
	     item=D->array[pos];
	     for(k=pos;k<D->top;k++)
	     {
		    D->array[k]=D->array[k+1];
		}
		D->array[D->top]=0;
	     D->top--;
     }
     
     if(D->top>-1){
	count=0;
	for(k=0;k<=D->top;k++)
	{
		count++;
	}
	if(count==D->capacity/2)
	{
		ShrinkArray(D);
	}
	return item;
}
}

int DeletionAtEnd(struct DAControl* D)
{
	int item,count=0,k;
	if(D->top==-1){
	  printf("Array is Empty");
     }
	  
	else{
		item=D->array[D->top];
		D->array[D->top]=0;
		D->top--;
     }
	
	if(D->top>-1){
	for(k=0;k<=D->top;k++)
	{
		count++;
	}
	if(count==D->capacity/2)
	{
		ShrinkArray(D);
	}
	return item;
}
}

void printArray(struct DAControl* D)
{
	int i;
	if(D->top==-1){
		printf("Array is Empty");
	}
	else{
		for(i=0;i<=D->top;i++)
		{
			printf("%d ",D->array[i]);
		}
	}
	
}

int menu()
{
	int c;
	system("cls");
	printf("\n1. Insert An Element Into Array");
	printf("\n2. Delete An Element From Array From End");
	printf("\n3. Delete An Element From Array From Any Position");
	printf("\n4. View The Status of the Array");
	printf("\n5. Print Array");
	printf("\n6. Exit");
	printf("\n\n Enter Your Choice");
	scanf("%d",&c);
	return c;
}


int main()
{
	struct DAControl* D;
	int info,position;
	D=createArray(3);
	while(1){
	switch(menu()){
		case 1:
			printf("\nEnter the info");
			scanf("%d",&info);
			Insertion(D,info);
			break;
		
		case 2:
			DeletionAtEnd(D);
			break;
		
		case 3:
			printf("\nEnter the position");
			scanf("%d",&position);
			DeletionAtAny(D,position);
			break;
		
		case 4:
			printf("\nPosition of last element is %d",D->top);
			printf("\nCapacity of array is %d",D->capacity);
			break;
		
		case 5:
			printArray(D);
			break;
		
		case 6:
			free(D->array);
			free(D);
			exit(0);
			break;
		
		default:
			printf("Invalid Choice");
		
			
	}
	getch();
}



}
