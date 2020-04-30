#include<stdio.h>

void selectionsort(int* A,int n,int init);

void selectionsort(int* A,int n,int init)
{
	int min,j,item,k;
	
	if(init<n){
		
		
	//finding minimum element//
	min=init;
	for(k=init;k<n;k++)
	{
		if(A[min]>A[k])
		  min=k;
	}
	//finding minimum element//
	
	
    //swapping//
	item=A[min];
	A[min]=A[init];
	A[init]=item;
	//swapping//
	
	
	selectionsort(A,n,init+1);
	
	
}
}

void print(int* A,int n){

int i;
for(i=0;i<n;i++)
	{
		printf("%d ",A[i]);
	}
}


int main()
{
	int n,init;
	int A[]={77,33,44,11,88,22,66,55};
	n=sizeof(A)/sizeof(int);
	init=0;
	selectionsort(A,n,init);
	print(A,n);
	
}
