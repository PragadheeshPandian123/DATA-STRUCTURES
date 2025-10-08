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
struct node * swap_in_pairs(struct node * head)
{
    struct node *curr=head;
    int temp;
    while(curr!=NULL && curr->next!=NULL)
    {
        temp=curr->data;
        curr->data=curr->next->data;
        curr->next->data=temp;
        curr=curr->next->next;
    }
    return head;
}

int main()
{
    struct node * head=create_node(1);
    head=append_node(head,2);
    head=append_node(head,3);
    head=append_node(head,4);
    head=append_node(head,5);
    head=append_node(head,6);
    head=append_node(head,7);
    head=append_node(head,8);
    head=append_node(head,9);
    // head=append_node(head,10);
    head=swap_in_pairs(head);
    // head=append_node(head,60);
    print_nodes(head);
    return 0;
}