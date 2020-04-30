
struct node{
	struct node* next;
	struct BTNode* address;
};

void push(struct node** S,struct BTNode* data);
struct BTNode* pop(struct node** S);
struct BTNode* peek(struct node** S);
void viewStack(struct node** S);
void removeStack(struct node** S);

struct node* createNode(struct BTNode* data){
	
	struct node* temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->address=data;
	temp->next=NULL;
	return temp;
}

void push(struct node** S,struct BTNode* data){
	
	struct node* temp=createNode(data);
	temp->next=*S;
	*S=temp;
}

struct BTNode* pop(struct node** S){
	
	struct node* D;
	struct BTNode* item;
	
	D=*S;
	if(D==NULL){
		return NULL;
		
	}
	else{
		*S=D->next;
		 item=D->address;
		 free(D);
		 return item;
	}
}

struct BTNode* peek(struct node** S){
	
	if(*S==NULL){
		return NULL;
	}
	else{
		return((*S)->address);
	}
}

void viewStack(struct node** S){
	
	struct node* T;
	T=*S;
	if(T==NULL){
		printf("Stack is empty");
	}
	else{
	while(T!=NULL){
		
		printf("%d ",T->address);
		T=T->next;
	}
}
}

void removeStack(struct node** S){
	
	while(*S!=NULL){
		pop(S);
	}
}
