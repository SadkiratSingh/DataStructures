#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include "DynamicArray.h"
#include "stack.h"

int prec(char x){
	
	if(x=='^'){
		return 5;
	}
	else if(x=='/'){
		return 4;
	}
	else if(x=='*'){
		return 3;
	}
	else if(x=='+'){
		return 2;
	}
	else if(x=='-'){
		return 1;
	}
}

infixToPostfix(char* Q,struct node** S,DAControl* D){
	
	push(S,'(');
	int i=0;
	while(Q[i] && *S!=NULL){
		if( (Q[i]>='A' && Q[i]<='Z') || (Q[i]>='a' && Q[i]<='z') ){
			
			Insertion(D,Q[i]);
		}
		
		else if(Q[i]=='('){
			
			push(S,Q[i]);
		}
		
		else if(Q[i]=='+' || Q[i]=='-' || Q[i]=='/' || Q[i]=='*'|| Q[i]=='^'){
			
			char s=peek(S);
			while(s!='(' && prec(s)>prec(Q[i])){
				Insertion(D,s);
				pop(S);
				s=peek(S);
			}
			push(S,Q[i]);
		}
		
		else if(Q[i]==')'){
			
			while((*S)->info!='('){
				
				Insertion(D,pop(S));
			}
			pop(S);
		}
		i++;
	}
}

int main(){
	
	char Q[50]={'A','+','B','/','C','*','(','D','-','A',')','^','F','^','H','\0'};
	int count=0;
	int i;
	for(i=0;Q[i];i++){
		count++;
	}
	Q[count]=')';
	Q[count+1]='\0';
	struct node* Stack=NULL;
	struct DAControl* D=createArray(5);
	infixToPostfix(Q,&Stack,D);
	printArray(D);
}
