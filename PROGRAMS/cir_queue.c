# include <stdio.h>
# include <stdlib.h>
# define MAX 10

int queue[MAX],front=-1,rear=-1;

void push(int val)
{
    if((front==0 && rear==MAX -1)||(front=rear+1)){
        printf("OVERFLOW . \n");
        return;
    }
    else{
        if(front==-1 && rear==-1){
            front=rear=0;
            queue[rear]=val;
        }
        if(rear==MAX-1){
            rear=0;
            queue[rear]=val;
        }
        else queue[++rear]=val;
        printf("Successfully pushed. \n");
    }
}

int pop(){
    if(front==-1 && rear==-1)
        printf("UNDERFLOW.\n");
    else{
        int val=queue[front];
        if(front==rear){
            front=rear=-1;
        }
        else{
            if(front==MAX-1){
                front=0;
            }
            else{
                front++;
            }
        }
        return val;
    }
}

