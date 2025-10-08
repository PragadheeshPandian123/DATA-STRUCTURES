# include <stdio.h>
# include <stdlib.h>

struct node{
    int data;
    struct node * next;
};

struct node * top= NULL;
struct node ** top_ref=&top;
void push(int );
void pop();
void display();
void peek();
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
                push(val);
                break;
            case 2:
                pop(top);
                break;
            case 3:
                peek(top);
                break;
            case 4:
                display(top);
        }
    }while(choice!=5);
    return 0;
}

void push(int data)
{
    struct node * temp=(struct node *)malloc(sizeof(struct node));
    temp->data=data;
    if(*top_ref==NULL)
    {
        temp->next=NULL;
        *top_ref=temp;
    }
    else{
        temp->next=*top_ref;
        *top_ref=temp;
    }
}

void pop(){
    if(*top_ref==NULL)
    {
        printf("Underflow error\n");
    }
    else{
        int val=(*top_ref)->data;
        struct node *temp=*top_ref;
        *top_ref=(*top_ref)->next;
        free(temp);
        printf("The popped value is : %d \n",val);
    }
}

void display()
{
    if(*top_ref==NULL)
    {
        printf("Empty Stack\n");
    }
    else{
        struct node * curr=*top_ref;
        while(curr!=NULL)
        {
            printf("%d ",curr->data);
            curr=curr->next;
        }
        printf("\n");
    }
}

void peek()
{
    if(*top_ref==NULL){
        printf("Empty Stack\n");
    }
    else{
        int val=(*top_ref)->data;
        printf("The topmost element is : %d \n",val);
    }
}