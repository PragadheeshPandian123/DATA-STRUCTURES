# include <stdio.h>
# define MAX 10
char st[MAX];
int TOP=-1;
void push(char st[],char data);
char pop(char st[]);
char peek(char st[]);
void display(char st[]);

int validity(char a[],char st[])
{
    int flag;
    push(st,a[0]);
    display(st);
    for(int i=1;i<MAX;i++)
    {
        flag=0;
        if((peek(st)=='(' && a[i]==')')||(peek(st)=='[' && a[i]==']')||(peek(st)=='{' && a[i]=='}'))
        {
            flag=1;
            pop(st);
            display(st);
        }
        else{
            flag=0;
            push(st,a[i]);
            display(st);
        }
    }
    if(TOP!=-1)
        flag=0;
    if(flag==1)
    {
        return 1;
    }
    return 0;
}
int main()
{
    char arr[10];
    printf("Enter the array: \n");
    for(int i=0;i<10;i++)
    {
        printf("Enter arr[%d]: ",i);
        scanf("%c",&arr[i]);
        getchar();
    }
    printf("The arrray is: \n");
    for(int i=0;i<10;i++)
    {
        printf("%c",arr[i]);
    }
    printf("\n");

    if(validity(arr,st))
        printf("Valid expression");
    else    
        printf("Invalid expression");

}
void push(char st[],char data)
{
    if(TOP==MAX-1)
        printf("Overflow Error\n");
    else{
        TOP=TOP+1;
        st[TOP]=data;
    }
}

char pop(char st[])
{
    if(TOP==-1)
        printf("Underflow error\n");
    else{
        char val=st[TOP];
        TOP=TOP-1;
        return val;
    }
}

char peek(char st[])
{
    if(TOP==-1)
        printf("Empty stack\n");
    else{
        char val=st[TOP];
        return val;
    }
}

void display(char st[])
{
    if(TOP==-1)
        printf("Empty Stack\n");
    else{
        for(int i=0;i<=TOP;i++)
        {
            printf("%c",st[i]);
        }
        printf("\n");
    }
}