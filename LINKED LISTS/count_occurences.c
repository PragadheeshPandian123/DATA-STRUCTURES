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

int count_all_occurences(struct node * head,int data)
{
    int count=0;
    struct node * ptr=head;
    while(ptr!=NULL)
    {
        if(ptr->data==data)
            count++;
        ptr=ptr->next;
    }
    return count;
}

int main()
{
    struct node * head=create_node(1);
    head=append_node(head,2);
    head=append_node(head,1);
    head=append_node(head,2);
    head=append_node(head,1);
    head=append_node(head,3);
    head=append_node(head,1);
    
    // head=append_node(head,60);
    print_nodes(head);
    int times=count_all_occurences(head,1);
    printf("\n%d\n",times);
    return 0;
}