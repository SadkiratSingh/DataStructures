#include<stdio.h>
void bubblesort(int* x,int s);

void bubblesort(int* x,int s)
{
	int temp,i,j,k;
	for(i=1;i<=s-1;i++)
	{
		for(j=0;j<s-i;j++)
		{
			temp=x[j];
			x[j]=x[j+1];
			x[j+1]=temp;
		}
	}
	for(k=0;k<=s-1;k++)
	{
		printf("%d ",x[k]);
	}
}

int main()
{
	int a[]={34,15,29,8};
	int s=sizeof(a)/sizeof(int);
	bubblesort(a,s);
}
