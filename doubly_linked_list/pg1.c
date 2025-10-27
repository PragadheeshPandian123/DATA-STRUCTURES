# include <stdio.h>
# include <stdlib.h>

typedef struct node 
{
    struct node * prev;
    int data;
    struct node * next;
}Node;

Node * reverse_list(Node * head)
{
    if(head==NULL)
    {
        printf("UNDERFLOW\n");
        return NULL;
    }
    else{
        Node * prev=NULL,*curr=head;
        while(curr!=NULL)
        {
            prev=curr->prev;
            curr->prev=curr->next;
            curr->next=prev;
            curr=curr->prev;
        }
        if(prev!=NULL)
        {
            head=prev->prev;
        }
    }
}