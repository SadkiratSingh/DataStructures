#include<stdio.h>

void InsertionSort(int* A,int n,int init);

void InsertionSort(int* A,int n,int init)
{
	int j,temp;
	
	if(init<n){
	for(j=init;j>0 && A[j]<A[j-1];j--)
	{
		temp=A[j];
		A[j]=A[j-1];
		A[j-1]=temp;
	}
	InsertionSort(A,n,init+1);
}
}

	

int main()
{
	int n,init;
	int A[]={64,25,12,22,11};
	n=sizeof(A)/sizeof(int);
	init=0;
	InsertionSort(A,n,init);
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d ",A[i]);
	}
}
