#include<stdio.h>
#include<math.h>

void Heapify(int* A,int n,int i)
{
	int max;
	int left=2*i+1;
	int right=2*i+2;
	max=i;
	int temp;
	
	if(left<n && A[left]>A[max]){
		max=left;
	}
	if(right<n && A[right]>A[max]){
		max=right;
	}
	
	if(max!=i){
		temp=A[i];
		A[i]=A[max];
		A[max]=temp;
		Heapify(A,n,max);
	}

	
}

int main()
{
	int A[]={4,10,3,16,15};
	int n=sizeof(A)/sizeof(int);
	
	int p=(n-2)/2;
	
	int i,j;
	for(j=p;j>=0;j--){
	   Heapify(A,n,j);
     }
	for(i=0;i<n;i++)
	{
		printf("%d ",A[i]);
	}
}
