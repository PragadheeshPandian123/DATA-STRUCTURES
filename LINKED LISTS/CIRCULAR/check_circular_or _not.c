# include <stdio.h>
# include <stdlib.h>
struct node 
{
    int data;
    struct node * next;
};
struct node * create_circular(int data)
{
    struct node * ptr=(struct node *)malloc(sizeof(struct node));
    ptr->data=data;
    ptr->next=ptr;
    return ptr;
}
struct node * append_node_circular(struct node * head,int data)
{
    struct node * ptr=(struct node *)malloc(sizeof(struct node));
    ptr->data=data;
    ptr->next=head;
    return head;
}
void print_nodes_circular(struct node * head)
{
    struct node * ptr=(struct node *)malloc(sizeof(struct node));
    do{
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }while(ptr!=head);
    printf("\n");
}
struct node * create_singly(int data)
{
    struct node * node=(struct node *)malloc(sizeof(struct node));
    node->data=data;
    node->next=NULL;
    return node;
}
struct node * append_node_singly(struct node * head,int data)
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
void print_nodes_ciruclar(struct node *head)
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
int check_circular_or_not_1(struct node * head)
{
    struct node * ptr;
    ptr=head;
    do{
        ptr=ptr->next;
    }while(ptr!=NULL && ptr!=head);
    if(ptr==head)
        return 1;
    else
        return 0;
}
int check_circular_or_not_2(struct node * head)
{
    struct node * slow=head,*fast=head;
    while(fast && fast->next)
    {
        if(slow==fast)
            return 1;
        slow=slow->next;
        fast=fast->next->next;
    }
    return 0;
}
int main()
{
    struct node * head1,*head2;
    head1=create_singly(1);
    head2=create_circular(1);

    // singly
    head1=append_node_singly(head1,2);
    head1=append_node_singly(head1,3);
    head1=append_node_singly(head1,4);
    head1=append_node_singly(head1,5);

    // ciruclar
    head2=append_node_circular(head2,2);
    head2=append_node_circular(head2,3);
    head2=append_node_circular(head2,4);
    head2=append_node_circular(head2,5);

    printf("%d %d",check_circular_or_not(head1),check_circular_or_not_2(head2));
    return 0;
}