////merge1 Function has a complexity of O(n)////

////merge2 Function has a complexity of O(n^2)////

////merge3 Function has a complexity of O(n^2)////

#include<stdio.h>

void merge1(int* A1,int* A2,int* A3,int n1,int n2){
	
	int i=0,j=0,k=0;
	
	while(i<n1 && j<n2){
		
		if(A1[i]>A2[j]){
			A3[k]=A2[j];
			j++;
		}
		else{
			A3[k]=A1[i];
			i++;
		}
		k++;
		
	}
	while(i<n1){
		A3[k]=A1[i];
		k++;
		i++;
	}
	while(j<n2){
		A3[k]=A2[j];
		k++;
		j++;
	}
	
}
///////////////////////////////////////////////////////////////////////////////////////////


void merge2(int* A1,int* A2,int n1,int n2){
	
	int i,j,temp;
	for(j=n2-1;j>=0;j--){
		for(i=0;i<n1;i++){
			if(A1[i]>A2[j]){
				temp=A1[i];
				A1[i]=A2[j];
				A2[j]=temp;
			}
		}
	}
}
//////////////////////////////////////////////////////////////////////////////////////////////

void merge3(int* A1,int* A2,int n1,int n2){
	
	int i,last,j;
	for(i=n2-1;i>=0;i--){
		
		last=A1[n1-1];
		
		for(j=n1-2;A1[j]>A2[i];j--){
			A1[j+1]=A1[j];
		}
		if(j!=n1-2 || last>A2[i]){
		A1[j+1]=A2[i];
		A2[i]=last;
	}
	}
	
}

int main(){
	
	int A1[]={9,13,19,56};
	int n1=sizeof(A1)/sizeof(int);
	
	int A2[]={2,4,18,30,45};
	int n2=sizeof(A2)/sizeof(int);
	
	int n3=n1+n2;
	int A3[n3];
	
	merge1(A1,A2,A3,n1,n2);
	
	int i;
	for(i=0;i<n3;i++){
		printf("%d ",A3[i]);
	}
	
	//merge2(A1,A2,n1,n2);
	//merge3(A1,A2,n1,n2);
	
//	for(int k=0;k<n1;k++){
//		printf("%d ",A1[k]);
//	}
//	printf("\n");
//	
//	for(int k=0;k<n2;k++){
//		printf("%d ",A2[k]);
//	}

}
