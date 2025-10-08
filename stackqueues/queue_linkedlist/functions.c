# include <stdio.h>
# include <stdlib.h>

typedef struct node {
    int data;
    struct node * next;
}Node;

Node * front=NULL,*rear=NULL;

void push(){
    int val;
    printf("Enter val: ");
    scanf("%d",&val);
    Node * temp=(Node *)malloc(sizeof(Node));
    temp->data=val;
    if(front==NULL && rear==NULL){
        front=rear=temp;
        temp->next=NULL;
    }
    else{
        rear->next=temp;
        rear=rear->next;
        rear->next=NULL;
    }
}

void pop(){
    if(front==NULL && rear==NULL){
        printf("UNDERFLOW\n");
        exit(1);
    }
    else{
        Node * temp=front;
        int val=front->data;
        front=front->next;
        free(temp);
        printf("The Value popped is: %d\n",val);
    }
}

void peek(){
    if(front==NULL){
        printf("UNDERFLOW\n");
    }
    int val;
    val=front->data;
    printf("The topmost element is: %d\n",val);
}

void display(){
    if(front==NULL){
        printf("QUEUE IS EMPTY\n");
    }
    Node * curr=front; 
    while(curr!=NULL){
        printf("%d ",curr->data);
        curr=curr->next;
    }
    printf("\n");
}
