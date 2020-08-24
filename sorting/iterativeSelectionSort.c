#include<stdio.h>

void selectionsort(int* A,int n);

void selectionsort(int* A,int n)
{
	int i,j,min,init,temp;
	
	for(i=1;i<n;i++)
	{
		
	   min=init=i-1;
	   for(j=init;j<n;j++)
	   {
	      if(A[min]>A[j])
	   	     min=j;
	   }
	   
	   temp=A[init];
	   A[init]=A[min];
	   A[min]=temp;
	   
    }
    
}

int main()
{
	int n,k;
	int A[]={77,33,44,11,88,22,66,55};
	n=sizeof(A)/sizeof(int);
	selectionsort(A,n);
	for(k=0;k<n;k++)
	{
		printf("%d ",A[k]);
	}
}



