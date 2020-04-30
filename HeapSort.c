#include<stdio.h>

void swap(int* A ,int a,int b)
{
	int temp;
	temp=A[a];
	A[a]=A[b];
	A[b]=temp;
}

void Heapify(int* A,int i,int n)
{
	int max;
	int left=2*i+1;
	int right=2*i+2;
	max=i;
	
	if(left<n && A[left]>A[max]){
		max=left;
	}
	if(right<n && A[right]>A[max]){
		max=right;
	}
	if(max!=i){
		swap(A,i,max);
		Heapify(A,max,n);
	}
}

void HeapFromArray(int* A,int n)
{
	int p=(n-2)/2;
	int j;
	for(j=p;j>=0;j--)
	{
		Heapify(A,j,n);
	}
}

void HeapSort(int* A,int n)
{
	HeapFromArray(A,n);
     int j;
	for(j=n;j>0;j--){
		
	int item=A[0];
	A[0]=A[j-1];
	A[j-1]=item;
	Heapify(A,0,j-1);
}
}

int main()
{
	int A[]={4,10,3,16,15};
	int n=sizeof(A)/sizeof(int);
	HeapSort(A,n);
	
	int k;
	for(k=0;k<n;k++)
	{
		printf("%d ",A[k]);
	}
	
}
