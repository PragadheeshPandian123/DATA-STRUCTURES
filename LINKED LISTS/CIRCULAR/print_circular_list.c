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
struct node * append_node (struct node * head,int data)
{
    struct node * ptr=(struct node *)malloc(sizeof(struct node));
    ptr->data=data;
    ptr->next=head;
    return head;
}
void print_nodes(struct node * head)
{
    struct node * ptr=(struct node *)malloc(sizeof(struct node));
    do{
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }while(ptr!=head);
    printf("\n");
}