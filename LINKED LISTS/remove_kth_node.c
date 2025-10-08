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
struct node *delete_kth_node(struct node * head,int k)
{
    struct node * prev=NULL,*curr=head;
    int counter=0;
    while(curr!=NULL)
    {
        counter++;
        if(counter%k==0)
        {
            if(prev==NULL)
            {
                return delete_all(head);
            }
            else
            {
            prev->next=curr->next;
            free(curr);
            curr=prev->next;
            }
        }
        else
        {
            prev=curr;
            curr=curr->next;            
        }
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
    head=append_node(head,10);
    
    // head=append_node(head,60);
    print_nodes(head);
    head=delete_kth_node(head,1);
    print_nodes(head);
    return 0;
}