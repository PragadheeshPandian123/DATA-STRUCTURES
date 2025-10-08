# include <stdio.h>
# define MAX 10
int st[MAX],TOP=-1;
void push(int st[],int data);
int pop(int st[]);
void peek(int st[]);
void display(int st[]);
int main()
{
    int arr[10];
    printf("Enter the array: \n");
    for(int i=0;i<10;i++)
    {
        printf("Enter arr[%d]: ",i);
        scanf("%d",&arr[i]);
    }
    printf("The arrray is: \n");
    for(int i=0;i<10;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");

    for(int i=0;i<10;i++)
    {
        push(st,arr[i]);
    }

    for(int i=0;i<10;i++)
    {
        arr[i]=pop(st);
    }
    
    printf("The arrray is: \n");
    for(int i=0;i<10;i++)
    {
        printf("%d ",arr[i]);
    }

}
void push(int st[],int data)
{
    if(TOP==MAX-1)
        printf("Overflow Error\n");
    else{
        TOP=TOP+1;
        st[TOP]=data;
    }
}

int pop(int st[])
{
    if(TOP==-1)
        printf("Underflow error\n");
    else{
        int val=st[TOP];
        TOP=TOP-1;
        return val;
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