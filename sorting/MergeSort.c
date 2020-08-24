////Merge Function has a complexity of O(n)////

#include<stdio.h>

void Merge(int* A,int s,int e,int m)
{
	int n1=m-s+1;
	int n2=e-m;
	int A1[n1],A2[n2];
	
	int l;
	for(l=0;l<n1;l++){
		A1[l]=A[s+l];
	}
	for(l=0;l<n2;l++){
		A2[l]=A[m+1+l];
	}

	int i=0,j=0,k=s;
	
	while(i<n1 && j<n2){
		
		if(A1[i]>A2[j]){
			A[k]=A2[j];
			j++;
		}
		else{
			A[k]=A1[i];
			i++;
		}
		k++;
	}
	
	while(i<n1){
		A[k]=A1[i];
		i++;
		k++;
	}
	
	while(j<n2){
		
		A[k]=A2[j];
		j++;
		k++;
	}
	
}


void MergeSort(int* A,int s,int e){
	
	if(e>s){
		
	int m=(s+e)/2;
	MergeSort(A,s,m);
	MergeSort(A,m+1,e);
	Merge(A,s,e,m);
}
	
}

int main()
{
	int A[]={10,8,7,54,34,67,90,87,31};
	int n=sizeof(A)/sizeof(int);
	int s=0;
	int e=n-1;
	MergeSort(A,s,e);
	int i;
	for(i=0;i<n;i++){
		printf("%d ",A[i]);
	}
	
}

