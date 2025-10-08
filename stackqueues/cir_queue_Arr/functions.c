# include <stdio.h>
# include <stdlib.h>
# define MAX 10
int queue[MAX],front=-1,rear=-1;

void push(){
    if((front==0 && rear==MAX-1)|| front==rear+1){
        printf("OVERFLOW\n");
        return;
    }
    else{
        if(front==-1 && rear==-1){
            front=rear=0;
        }
        else if(rear==MAX-1){
            rear=0;
        }
        else{
            rear++;
        }
    }
    int val;
    printf("Enter val: ");
    scanf("%d",&val);
    queue[rear]=val;
}

void pop(){
    if(front==-1){
        printf("UNDERFLOW\n");
        return;
    }
    int val=queue[front];
    if(front==rear){
        front=rear=-1;
    }
    else if(front==MAX-1){
        front=0;
    }
    else{
        front++;
    }
}

void peek(){
    if(front==-1){
        printf("UNDERFLOW\n");
        return;
    }
    int val=queue[front];
    printf("The topmost element is : %d\n",val);
}

void display(){
    if(front==-1){
        printf("Stack Empty\n");
        return;
    }

    if(front<=rear){
        for(int i=front;i<=rear;i++){
            printf("%d ",queue[i]);
        }
        printf("\n");
    }
    else{
        int i=front;
        while(i<=MAX-1){
            printf("%d ",queue[i]);
            i++;
        }
        i=0;
        while(i<=rear){
            printf("%d ",queue[i]);
            i++;
        }
        printf("\n");
    }
}