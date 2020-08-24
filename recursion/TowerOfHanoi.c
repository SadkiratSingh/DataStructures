#include<stdio.h>

void TOH(char BEG,char MID,char END,int n)
{
	if(n>0){
	TOH(BEG,END,MID,n-1);
	printf("\n%c-->%c",BEG,END);
	TOH(MID,BEG,END,n-1);
}
}

int main(){
	
	int n=4;
	char BEG='A';
	char MID='B';
	char END='C';
	TOH(BEG,MID,END,n);
}
