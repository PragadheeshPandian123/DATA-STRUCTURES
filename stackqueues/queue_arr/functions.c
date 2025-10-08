# include <stdio.h>
# include <stdlib.h>
# define MAX 10

int queue[MAX],front=-1,rear=-1;
void push(){
    if(rear==MAX-1){
        printf("OVERFLOW\n");
        exit(1);
    }
    else{
        if(front==-1 && rear==-1){
            front=rear=0;
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
    if(rear==-1 || front > rear){
        printf("UNDERFLOW\n");
        exit(1);
    }
    else{
        int val=queue[front];
        front++;
        printf("The value popped is: %d\n",val);
        if(front>rear){
            front=rear=-1;
        }
    }
}

void peek(){
    if(rear==-1){
        printf("UNDERFLOW\n");
        exit(1);
    }
    int val=queue[front];
    printf("The topmost element is: %d",val);
}

void display(){
    if(rear==-1){
        printf("Queue is Empty\n");
        return;
    }
    for(int i=front;i<=rear;i++){
        printf("%d ",queue[i]);
    }
    printf("\n");
}