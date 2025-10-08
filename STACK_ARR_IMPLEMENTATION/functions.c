# include <stdio.h>
# include <stdlib.h>
# include "functions.h"


void create_stack(){

    if(stack!=NULL){
        printf("Delete the stack first! \n");
        delete_stack();
        return;
    }
    int data;
    printf("Enter overflow limit of stack( >=1): ");
    scanf("%d",&max);
    if(max==0){
        printf("Invalid value.Try again\n");
        create_stack();
        return;
    }
    stack=(int *)malloc(max*sizeof(int));
    printf("Enter data: ");
    scanf("%d",&data);

    stack[++top]=data;
    printf("Stack successfully created\n");
}

void push(){
    if(stack==NULL){
        create_stack();
        return;
    }
    if(top==max-1){
        printf("Stack Overflow.\n");
        return;
    }
    else{
        int data;
        printf("Enter data: ");
        scanf("%d",&data);
        stack[++top]=data;
    }
}

void pop(){
    if(stack==NULL){
        printf("Stack Underflow\n");
        return;
    }  
    else{
        int val;
        val=stack[top--];
        printf("The popped value is : %d",val);
        if(top==-1){
            stack=NULL;
        }
    }
}

void peek(){
    if(stack==NULL){
        printf("Stack Underflow\n");
        return;
    }
    else{
        int val;
        val=stack[top];
        printf("The topmost element of stack is : %d",val);
    }
}

void display(){
    if(stack==NULL){
        printf("Empty Stack\n");
    }
    else{
        for(int i=0;i<=top;i++){
            printf("%d ",stack[i]);
        }
        printf("\n");
    }
}

void delete_stack(){
    if(stack==NULL){
        printf("Empty Stack \n");
        return;
    }
    else{
        free(stack);
        stack=NULL;
    }
}
