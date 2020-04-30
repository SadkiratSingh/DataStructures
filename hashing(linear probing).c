#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

int minHashTableSize=5;

struct student{
	int rollno;
	char name[50];
	char course[50];
};

struct hash{
	struct student** stu_table;
	int capacity;
	int count;
};

struct hash* createHashTable(int);
struct student* createStudent();
int hashing(int,struct hash*);
int checkroll(int);
int checkstring(char[]);
void insertIntoTable(int,struct student*,struct hash*);
void doubleSize(struct hash*,struct student*,int);
int searchStudent(struct hash*,int);
void deleteStudent(struct hash*,int);
void reduceSize(struct hash*);
void viewTable(struct hash*);
void deleteTable(struct hash*);
int menu();

struct hash* createHashTable(int size){
	
	struct hash* temp;
	int j;
	temp=(struct hash*)malloc(sizeof(struct hash));
	temp->capacity=size;
	temp->count=0;
	temp->stu_table=(struct student**)malloc(temp->capacity*sizeof(struct student*));
	for(j=0;j<=temp->capacity-1;j++){
		temp->stu_table[j]=NULL;
	}
	return temp;
}

void doubleSize(struct hash* h,struct student* s,int key){
	
	struct student** temp_stu,**temp;
	int old_cap=h->capacity;
	h->capacity=2*h->capacity;
	h->count=0;
	temp_stu=(struct student**)malloc(h->capacity*sizeof(struct student*));
	int j=0;
	while(j<h->capacity){
		temp_stu[j]=NULL;
		j++;
	}
	temp=h->stu_table;
	h->stu_table=temp_stu;
	
	for(j=0;j<old_cap;j++){
		insertIntoTable(temp[j]->rollno,temp[j],h);
	}
	insertIntoTable(key,s,h);
	free(temp);
}

int checkroll(int rollno){
	if(rollno<=0){
		return 0;
	}
	else{
		return 1;
	}
}

int checkstring(char ch[]){
	
	int j;
	for(j=0;ch[j]!='\n';j++){
		if(!isalpha(ch[j])){
			return 0;
		}
	}
	if(ch[0]=='\n'){
		return 0;
	}	
	else{
		return 1;
	}
}

void reduceSize(struct hash* h){
	
	struct student** temp_stu,**temp;
	int old_cap=h->capacity;
	h->capacity=h->capacity/2;
	temp_stu=(struct student**)malloc(h->capacity*sizeof(struct student*));
	int j=0;
	while(j<h->capacity){
		temp_stu[j]=NULL;
		j++;
	}
	temp=h->stu_table;
	h->stu_table=temp_stu;
	for(j=0;j<old_cap;j++){
		if(temp[j]!=NULL && temp[j]->rollno!=-1){
			insertIntoTable(temp[j]->rollno,temp[j],h);
		}
	}
	free(temp);
}

struct student* createStudent(){
	
	struct student* stu;
	int rollno,i;
	char* pos;
	char name[50],course[50],ch[50];
	
	printf("Enter roll no");
	scanf("%d",&rollno);
	while ((getchar()) != '\n'); 
	
	if(checkroll(rollno)){
		goto nameinput;
	}
	else{
		return NULL;
	}
	nameinput:
		printf("Enter name");
	     fgets(name,50,stdin);
	     if(checkstring(name)){
	     	
	     	pos=strchr(name,'\n');
	     	if(pos){
	     		*pos='\0';
			}
	     	goto courseinput;
		}
		else{
			return NULL;
		}
		courseinput:
			printf("Enter course");
	          fgets(course,50,stdin);
	          if(checkstring(course)){
	          	
	          	pos=strchr(name,'\n');
	     	     if(pos){
	     		     *pos='\0';
			     }
	          	goto create;
			}
			else{
				return NULL;
			}
	          create:
	          	stu=(struct student*)malloc(sizeof(struct student));
	               strcpy(stu->course,course);
                    strcpy(stu->name,name);
	               stu->rollno=rollno;
	               return stu;
		
}

int hashing(int key,struct hash* h){
	
	return(key%(h->capacity));
}

void insertIntoTable(int key,struct student* s,struct hash* h){
	
	int index=hashing(key,h);
	
	if(h->stu_table[index]==NULL){
		h->stu_table[index]=s;
		h->count++;
	}
	else if(h->stu_table[index]->rollno==-1){
		free(h->stu_table[index]);
		h->stu_table[index]=s;
		h->count++;
	}
	else{
		index=0;
		while((index<h->capacity) && (h->stu_table[index]!=NULL) && (h->stu_table[index]->rollno!=-1)){
			index++;
		}
		if(index<h->capacity){
			h->stu_table[index]=s;
		     h->count++;
	     }
	     else{
	     	doubleSize(h,s,key);
		}
	}
	
}

int searchStudent(struct hash* h,int key){
	
	int index=hashing(key,h);
	if(h->stu_table[index]!=NULL){
		
	if(h->stu_table[index]->rollno==key){  
		printf("%d\n",h->stu_table[index]->rollno);
		printf("%s\n",h->stu_table[index]->name);
		printf("%s\n",h->stu_table[index]->course);
		return index;
	}
	else{ 
		index=0;
		while((index<h->capacity) && (h->stu_table[index]!=NULL) && (h->stu_table[index]->rollno!=key)){
			index++;
		}
		if(index==h->capacity||!h->stu_table[index])
		{
			printf("student not present");
			return -1;
		}
		else{
			printf("%d\n",h->stu_table[index]->rollno);
		     printf("%s\n",h->stu_table[index]->name);
		     printf("%s\n",h->stu_table[index]->course);
		     return index;
		}
	}
     }
     else{
     	printf("student not present");
     	return -1;
	}
}

void deleteStudent(struct hash* h,int key){
	
	int index=searchStudent(h,key);
	if(index!=-1){
		
	struct student* dummy_stu;
	dummy_stu=(struct student*)malloc(sizeof(struct student));
	strcpy(dummy_stu->course,"$");
	strcpy(dummy_stu->name,"$");
	dummy_stu->rollno=-1;
	free(h->stu_table[index]);
	h->stu_table[index]=dummy_stu;
	h->count--;
     }
     if(h->count==(h->capacity/2) && h->capacity>minHashTableSize){
     	reduceSize(h);
	}
}

void viewTable(struct hash* h){
	
	     int j;
		for(j=0;j<=h->capacity-1;j++){
			if(!h->stu_table[j] || h->stu_table[j]->rollno==-1){
				printf("Nil\tNil\tNil\tNil\n");
			}
			else{
				printf("%d\t%d\t%s\t%s\n",j+1,h->stu_table[j]->rollno,h->stu_table[j]->name,h->stu_table[j]->course);
			}
		}
		
}

void deleteTable(struct hash* h){
	
	int j;
	for(j=0;j<=h->capacity-1;j++){
		if(h->stu_table[j]){
			free(h->stu_table[j]);
		}
	}
	free(h->stu_table);
	free(h);
}

int menu(){
	system("cls");
	int ch;
	printf("1.Enter student into table\n");
	printf("2.search student\n");
	printf("3.delete student from table\n");
	printf("4.View Table\n");
	printf("5.Number of Students\n");
	printf("6.Delete Table\n");
	printf("enter your choice");
	scanf("%d",&ch);
	while ((getchar()) != '\n'); 
     return ch;
}

int main(){
	
	struct hash* H;
	struct student* S;
	int r_no;
	H=createHashTable(minHashTableSize);
	while(1){
		switch(menu()){
			
			case 1:
				S=createStudent();
                    if(S){
                    	insertIntoTable(S->rollno,S,H);
				}
				break;
				
			case 2:
				printf("Enter the roll no");
				scanf("%d",&r_no);
				while ((getchar()) != '\n'); 
				searchStudent(H,r_no);
				break;
			
			case 3:
				printf("Enter the roll no");
				scanf("%d",&r_no);
				while ((getchar()) != '\n'); 
				deleteStudent(H,r_no);
				break;
				
			case 4:
				viewTable(H);
				break;
			
			case 5:
				printf("%d",H->count);
				break;
			
			case 6:
				deleteTable(H);
				exit(0);
				break;
			
			default:
				printf("enter valid choice");
			
		}
		getch();
	}
	
}
