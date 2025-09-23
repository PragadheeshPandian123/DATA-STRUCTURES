# include <stdio.h>
# include <stdlib.h>
# define MAX 5

int st[MAX],TOP=-1;
void push(int st[],int data);
void pop(int st[]);
void peek(int st[]);
void display(int st[]);
int main()
{
    int choice,val;
    do{
        printf("MAIN MENU: \n");
        printf("1.PUSH \n");
        printf("2.POP \n");
        printf("3.PEEK \n");
        printf("4.DISPLAY \n");
        printf("5.EXIT\n");
        printf("Enter a choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter the value to be pushed: ");
                scanf("%d",&val);
                push(st,val);
                break;
            case 2:
                pop(st);
                break;
            case 3:
                peek(st);
                break;
            case 4:
                display(st);
        }
    }while(choice!=5);
    return 0;

}
void push(int st[],int data)
{
    if(TOP==MAX-1)
        printf("Overflow Error\n");
    else{
        TOP=TOP+1;
        st[TOP]=data;
        printf("Successfully inserted into the stack.");
    }
}

void pop(int st[])
{
    if(TOP==-1)
        printf("Underflow error\n");
    else{
        int val=st[TOP];
        TOP=TOP-1;
        printf("The value popped is: %d",val);
    }
}

void peek(int st[])
{
    if(TOP==-1)
        printf("Empty stack\n");
    else{
        int val=st[TOP];
        printf("The Topmost element is : %d",val);
    }
}

void display(int st[])
{
    if(TOP==-1)
        printf("Empty Stack\n");
    else{
        for(int i=0;i<=TOP;i++)
        {
            printf("%d ",st[i]);
        }
        printf("\n");
    }
}