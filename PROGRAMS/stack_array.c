# include <stdio.h>
# include <stdlib.h>
# define MAX 100

int stack[MAX],top=-1;

void push(int val){
    if(top==MAX-1){
        printf("OVERFLOW\n");
        return;
    }
    else{
        stack[++top]=val;
        printf("Successfully inserted. \n");
    }
}

int pop(){
    if(top==-1){
        printf("UNDERFLOW\n");
        return -1;
    }
    else
    {
        int val=stack[top--];
        printf("Successfully popped\n");
        return val;
    }
}

void display(){
    if(top==-1){
        printf("Empty Stack \n");
        return;
    }
    else{
        for(int i=top;i>=0;i--)
        {
            printf(" %d ",stack[i]);
        }
        printf("\n");
    }
}

int peek()
{
    if(top==-1){
        printf("UNDERFLOW \n");
        return -1;
    }
    else{
        return stack[top];
    }
}

int main()
{
    int choice,val;
    do
    {
        printf("=============  Stack Menu (Array) ============ \n");
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