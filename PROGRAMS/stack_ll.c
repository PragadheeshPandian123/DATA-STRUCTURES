# include <stdio.h>
# include <stdlib.h>

typedef struct node {
    int data;
    struct node * next;
}Node;

Node * top=NULL;

void push(int val){
    if(top==NULL){
        Node * newNode=(Node *)malloc(sizeof(Node));
        newNode->data=val;
        newNode->next=NULL;
        top=newNode;
        printf("Successfully inserted . \n");
    }
    else{
        Node * newNode=(Node *)malloc(sizeof(Node));
        newNode->data=val;
        newNode->next=top;
        top=newNode;
        printf("Successfully inserted . \n");
    }
}

int pop()
{
    if(top==NULL){
        printf("UNDERFLOW \n");
        return -1;
    }
    else{
        Node * temp=top;
        top=top->next;
        int val=temp->data;
        free(temp);
        printf("Successfully popped. \n");
        return val;
    }
}

int peek()
{
    if(top==NULL){
        printf("UNDERFLOW \n");
        return -1;
    }
    else{
        return top->data;
    }
}

void display ()
{
    if(top==NULL){
        printf("EMPTY STACK \n");
        return;
    }
    else{
        Node * curr=top;
        while(curr!=NULL){
            printf(" %d ",curr->data);
            curr=curr->next;
        }
        printf("\n");
        return;
    }
}

int main()
{
    int choice,val;
    do
    {
        printf("=============  Stack Menu (Linked List) ============ \n");
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