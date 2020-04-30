#include<stdio.h>

int MaxMin(int* A,int start,int end){
	
	int mid,max1,max2;
	
	if(end>start){
		
	mid=(start+end)/2;
	max1=MaxMin(A,start,mid);
	max2=MaxMin(A,mid+1,end);
	
	if(max1>max2)
	   return max1;
	else
	   return max2;
    }
    else
      return A[start];
     
} 

int main(){
	
	int A[]={63,52,34,67,89,23,45};
	int n=sizeof(A)/sizeof(int);
	int start=0;
	int end=n-1;
	int max=MaxMin(A,start,end);
	printf("%d",max);
}
