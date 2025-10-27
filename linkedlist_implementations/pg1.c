# include <stdio.h>
# include <stdlib.h>

typedef struct node
{
    int data;
    struct node * next;
}Node;

void reverse_list(Node * head)
{
    if(head==NULL)
    {
        printf("EMPTY\n");
        return NULL;
    }
    else{
        Node * prev=NULL,*curr=head,*next=head;
        while(curr!=NULL)
        {
            next=next->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        head=prev;
    }
}