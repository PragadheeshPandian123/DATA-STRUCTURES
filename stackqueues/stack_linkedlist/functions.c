# include <stdio.h>
# include <stdlib.h>

typedef struct node{
    int data;
    struct node * next;
} Node;

Node * top=NULL;

void push(){
    int val;
    printf("Enter val: ");
    scanf("%d",&val);
    Node * temp=(Node *)malloc(sizeof(Node));
    temp->data=val;
    if(top==NULL){
        top=temp;
        temp->next=NULL;
    }
    else{
        temp->next=top;
        top=temp;
    }
}

void pop(){
    if(top==NULL){
        printf("UNDERFLOW\n");
        return;
    }
    Node * ptr=top;
    int val=top->data;
    top=top->next;
    free(ptr);
    printf("The popped value is: %d\n",val);
}

void peek(){
    if(top==NULL){
        printf("Underflow\n");
        return;
    }
    
    int val=top->data;
    printf("The topmost value is: %d\n",val);
}

void display(){
    if(top==NULL){
        printf("Stack Empty\n");
        return;
    }

    Node * curr=top;
    while(curr!=NULL){
        printf("%d ",curr->data);
        curr=curr->next;
    }
    printf("\n");
}