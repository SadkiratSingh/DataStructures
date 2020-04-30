#include<stdio.h>


void InsertionSort(int* A,int n);

void InsertionSort(int* A,int n)
{
	int i,item,j;
	for(i=1;i<=n;i++)
	{
		item=A[i-1];
		for(j=i-2; j>=0 && A[j]>item;j--)
		{
			A[j+1]=A[j];
		}
		A[j+1]=item;
	}
}

int main()
{
	int n,i;
	int A[]={64,25,12,22,11};
	n=sizeof(A)/sizeof(int);
	InsertionSort(A,n);
	for(i=0;i<n;i++)
	{
		printf("%d ",A[i]);
	}
}
