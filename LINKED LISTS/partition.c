# include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node * next;
};
struct node * create_node(int data)
{
    struct node * node=(struct node *)malloc(sizeof(struct node));
    node->data=data;
    node->next=NULL;
    return node;
}
struct node * append_node(struct node * head,int data)
{
    struct node * node=(struct node *)malloc(sizeof(struct node));
    node->data=data;
    node->next=NULL;
    struct node * ptr=head;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    ptr->next=node;
    return head;
}
void print_nodes(struct node *head)
{
    struct node * ptr=head;
    if(head==NULL)
    {
        printf("Empty linked list \n");
        return ;
    }
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}
struct node * delete_all(struct node * head)
{
    struct node * ptr=head;
    while(ptr!=NULL)
    {
        struct node * temp=ptr;
        ptr=ptr->next;
        free(temp);
    }
    return NULL;
}

struct node * push_data(struct node * tail,int data)
{
    struct node * temp=(struct node * )malloc(sizeof(struct node));
    temp->data=data;
    temp->next=NULL;

    tail->next=temp;
    tail=temp;
    return tail;
}

struct node * partition (struct node * head,int x)
{
    struct node dummy;
    dummy.data=-1;
    dummy.next=NULL;
    struct node * tail=&dummy,*curr=head;
    while(curr!=NULL)
    {
        if(curr->data<x)
            tail=push_data(tail,curr->data);
        curr=curr->next;
    }
    curr=head;
    while(curr!=NULL)
    {
        if(curr->data==x)
            tail=push_data(tail,curr->data);
        curr=curr->next;
    }
    curr=head;
    while(curr!=NULL)
    {
        if(curr->data>x)
            tail=push_data(tail,curr->data);
        curr=curr->next;
    }
    return dummy.next;
}

int main()
{
    struct node * head=create_node(10);
    head=append_node(head,4);
    head=append_node(head,20);
    head=append_node(head,10);
    head=append_node(head,3);
    
    print_nodes(head);
    head=partition(head,3);
    print_nodes(head);
    return 0;
}