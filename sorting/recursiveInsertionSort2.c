#include<stdio.h>

void InsertionSort(int* A,int n);

void InsertionSort(int* A,int n)
{
	int item,j;
	if(n>0)
	{
		InsertionSort(A,n-1);
		
		item=A[n-1];
		for(j=n-2;j>=0 && A[j]>item;j--)
		
		     A[j+1]=A[j];
		
	     A[j+1]=item;
		
	}
}


int main()
{
	int n;
	int A[]={64,25,12,22,11};
	n=sizeof(A)/sizeof(int);
	InsertionSort(A,n);
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d ",A[i]);
	}
}
