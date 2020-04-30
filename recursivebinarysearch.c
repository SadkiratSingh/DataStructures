#include<stdio.h>

void BinarySearch(int* A,int start,int end,int x){
	
	int mid;
	if(end>start){
		mid=(end+start)/2;
		if(A[mid]==x){
			printf("Search Successful");
		}
	     else if(x>A[mid]){
			BinarySearch(A,mid+1,end,x);
		}
		else{
			BinarySearch(A,start,mid,x);
		}
	}
	else{
	     printf("Search Unsuccessful");
	}
}

int main(){
	int A[]={23,34,45,52,63,67,89};
	int n=sizeof(A)/sizeof(int);
	int start=0;
	int end=n-1;
	int x=52;
	BinarySearch(A,start,end,x);
}
