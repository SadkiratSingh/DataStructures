#include<stdio.h>
#include<conio.h>
void binarysearch(int* x,int s)
{
	int temp,i,j,n,k;
	
	int f=0,l=s-1,m=(f+l)/2,item;
	
	for(i=1;i<s;i++)
	{
		for(j=0;j<s-i;j++)
		{
			if(x[j]>x[j+1]){
			temp=x[j];
			x[j]=x[j+1];
			x[j+1]=temp;
		}
		}
	}
	
	for(k=0;k<s;k++)
	{
		printf("%d ",x[k]);
	}
	
	printf("\nWhich item do you want to search?");
	scanf("%d",&item);
	
	while(x[m]!=item && f<=l)
	{
		if(item>x[m])
			f=m+1;
			
		else if(item<x[m])
		    l=m-1;
		m=(f+l)/2;
	}
	if(f>l)
	   printf("\nitem not found");
	else
	   printf("\nitem found");
}



int main()
{
	int a[]={25,31,43,11,17,64,37,81,90,100};
	int n=sizeof(a)/sizeof(int);
	binarysearch(a,n);
}
