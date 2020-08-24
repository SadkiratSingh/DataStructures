//partition method should have a complexity of O(n)//

#include<stdio.h>

void swap(int* A,int i,int j){
	int temp;
	temp=A[i];
	A[i]=A[j];
	A[j]=temp;
}

int partition(int* A,int start,int end){
	
	int j,i,pivot;
	pivot=end;
	j=start-1;
	for(i=start;i<=end-1;i++){
		if(A[i]<A[pivot]){
			j++;
			swap(A,i,j);
		}
	}
	swap(A,j+1,end);
	pivot=j+1;
	return pivot;
	
}

void QuickSort(int* A,int start,int end)
{
	int pivot;
	if(end>start){
	  
	  pivot=partition(A,start,end); 	
       QuickSort(A,start,pivot-1);
       QuickSort(A,pivot+1,end);
}
}


int main()
{
	int A[]={52,37,63,14,17,8,6,25};
	int n=sizeof(A)/sizeof(int);
	int start,end;
	end=n-1;
	start=0;
	QuickSort(A,start,end);
	int i;
	for(i=0;i<n;i++)
		printf("%d ",A[i]);
}
