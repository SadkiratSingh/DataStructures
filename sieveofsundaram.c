//time-complexity of nlogn//

#include<stdio.h>
#include<stdbool.h>

void sieveOfSundaram(int n){
      
     int nNew=(n-2)/2;
     bool marked[nNew];
     int i,j,k,sum;
     for(i=0;i<nNew;i++){
     	marked[i]=false;
	}
	for(j=1;j<=nNew;j++){
		k=1;
		while(k<=j && j+k+2*j*k<=nNew){
			marked[(j+k+2*j*k)-1]=true;
			k++;
		}
	}
	printf("%d ",2);
	for(i=0;i<nNew;i++){
		if(marked[i]==0){
			printf("%d ",2*(i+1)+1);
		}
	}
}

int main(){
	int x;
	printf("Enter a number");
	scanf("%d",&x);
	while((getchar())!='\n');
	sieveOfSundaram(x);
}
