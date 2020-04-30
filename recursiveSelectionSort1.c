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
	
	
    //making space for sorted//
	item=A[min];
	for(j=min;j>init;j--)
	{
		A[j]=A[j-1];
	}
	A[j]=item;
	//making space for sorted//
	
	
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
	int A[]={88,77,66,55,44};
	n=sizeof(A)/sizeof(int);
	init=0;
	selectionsort(A,n,init);
	print(A,n);
	
}
