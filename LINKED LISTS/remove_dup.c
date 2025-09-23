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
struct node * remove_duplicates_sorted(struct node * head)
{
    struct node * prev=NULL,*curr=head,*temp;
    while(curr!=NULL)
    {
        if(prev && curr->data==prev->data)
        {
            temp=curr;
            prev->next=curr->next;
            curr=curr->next;
            free(temp);
        }
        else{
            prev=curr;
            curr=curr->next;
        }
    }
    return head;
}

struct node * remove_duplicates_unsorted(struct node * head)
{
    struct node * curr1=head,*curr2=NULL,*temp,*prev=NULL;
    while(curr1!=NULL)
    {
        prev=curr1;
        curr2=curr1->next;
        while(curr2!=NULL)
        {
            if(curr1->data==curr2->data)
            {
                temp=curr2;
                prev->next=curr2->next;
                curr2=curr2->next;
                free(temp);
            }
            else
            {
            prev=curr2;
            curr2=curr2->next;
            }
        }
        curr1=curr1->next;
    }
    return head;
}

int main()
{
    struct node * head=create_node(12);
    head=append_node(head,11);
    head=append_node(head,12);
    head=append_node(head,21);
    head=append_node(head,41);
    head=append_node(head,43);
    head=append_node(head,21);
    // head=append_node(head,8);
    // head=append_node(head,9);
    // head=append_node(head,10);
    print_nodes(head);
    head=remove_duplicates_unsorted(head);
    // head=append_node(head,60);
    print_nodes(head);


    return 0;
}