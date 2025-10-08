# include <stdio.h>
# include <stdlib.h>
# define MAX 10

int queue[MAX],front=-1,rear=-1;
int isFull(){
    if(front==(rear+1)%MAX)return 1;
    else return 0;
}
int isEmpty(){
    if(front==-1)return 0;
}

void push(){
    if(isFull()){
        printf("OVERFLOW\n");
        exit(1);
    }
    if(isEmpty()){
        front=rear=0;
    }
    else{
        rear=(rear + 1)%MAX;
    }
    int val;
    printf("Enter val: ");
    scanf("%d",&val);
    queue[rear]=val;
}

void pop(){
    if(isEmpty()){
        printf("UNDERFLOW\n");
        exit(1);
    }
    
    int val=queue[front];
    if(front==rear){
        front=rear=-1;
    }
    else
        front=(front + 1)%MAX;
    printf("The value popped is: %d \n",val);
    
}

void peek(){
    if(isEmpty()){
        printf("UNDERFLOW\n");
    }
    int val=queue[front];
    printf("The topmost element is: %d\n",val);
}

void display(){
    if(isEmpty()){
        printf("Queue is Empty\n");
        return;
    }
    int i=front;
    while(1){
        printf("%d ",queue[i]);
        if(i==rear)break;
        i=(i+1)%MAX;
    }
    printf("\n");
}

int main(){
    int choice;
    do{
        printf("1.Push\n2.Pop\n3.Peek\n4.Display\n5.Quit");
        printf("\nEnter: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
        }
        if(choice!=5){
            display();
        }
    }while(choice!=5);
    return 0;
}