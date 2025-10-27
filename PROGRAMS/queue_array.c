# include <stdio.h>
# include <stdlib.h>
# define MAX 10

int queue[MAX],front=-1,rear=-1;

void push(int val)
{
    if(rear==MAX-1){
        printf("OVERFLOW \n");
        return;
    }
    else{
        if(front==-1 && rear==-1)front=rear=0;
        else rear++;
        queue[rear]=val;
        printf("Successfully inserted. \n");
    }
}

int pop(){
    if(front==-1 || front > rear){
        printf("UNDERFLOW \n");
        return -1;
    }
    else
    {
        int val=queue[front++];
        if(front > rear){
            front=rear=-1;
        }
        printf("Successfully popped \n");
        return val;
    }
}

int peek()
{
    if(front==-1 || front > rear){
        printf("UNDERFLOW \n");
        return -1;
    }
    else{
        return queue[front];
    }
}

void display()
{
    if(front==-1 && rear==-1){
        printf("EMPTY QUEUE. \n");
        return;
    }
    else{
        for(int i=front;i<=rear;i++)
        {
            printf(" %d ",queue[i]);
        }
        printf(" \n");
    }
}

int main()
{
    int choice,val;
    do
    {
        printf("=============  Queue Menu (Array) ============ \n");
        printf(" 1.Push \n 2.Pop \n 3.Display \n 4.Peek \n 5.Quit \n");
        printf("Enter choice : \n ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("Enter value : ");
            scanf("%d",&val);
            push(val);
            break;
        case 2:
            val=pop();
            if(val!=-1)printf("The popped value is : %d \n",val);
            break;
        case 3:
            display();
            break;
        case 4 :
            val=peek();
            if(val!=-1)printf("The peek value is : %d \n",val);
            break;
        case 5:
            printf("Exiting...");
            break;
        default:
            break;
        }
    } while (choice!=5);
    return 0;
}