#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include "stack.h"

int abs(int a,int b){
	
	if((a-b)<0){
		return b-a;
	}
	else{
		return a-b;
	}
}

int evalPostfix(struct node** S,char* P){
	
	int i=0;
	while(P[i]!=')'){
		
		if( (P[i]>='0') && (P[i]<='9')){
			int o=P[i]-'0';
			push(S,o);
		}
		else{
			int s1=pop(S);
			int s2=pop(S);
               switch(P[i]){
               	
               	case '+':
               		push(S,s1+s2);
               		break;
               	
               	case '-':
               		push(S,abs(s1,s2));
               		break;
               	
               	case '*':
               		push(S,s1*s2);
                         break;
				
				case '/':
				     push(S,s2/s1);
					break;
				
				case '^':
				     push(S,s1^s2);
					break;
				
			}
	    }
	    i++;	
	}
	return(peek(S));
}

int main(){
	
	char P[50]={'4','3','*','6','7','+','5','-','+','\0'};
	int count=0;
	int i;
	for(i=0;P[i];i++){
		count++;
	}
	P[count]=')';
	P[count+1]='\0';
	struct node* Stack=NULL;
	printf("%d",evalPostfix(&Stack,P));
}
