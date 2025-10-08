# include <stdio.h>
# include <stdlib.h>
struct node
{
    int data;
    struct node * next;
};
struct node * create_cll(int data)
{
    struct node * ptr=(struct node * )malloc(sizeof(struct node));
    ptr->data=data;
    ptr->next=ptr;
    return ptr;
}
struct node * append_node(struct node * head,int data)
{
    struct node * ptr=(struct node * )malloc(sizeof(struct node));
    ptr->data=data;
    ptr->next=NULL;
    struct node * curr=head;
    do
    {
        curr=curr->next;
    } while (curr->next!=head);
    curr->next=ptr;
    ptr->next=head;
    return head;
}
void * print_nodes(struct node * head)
{
    struct node * ptr=head;
    do{
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }while(ptr!=head);
    printf("\n");
}
int check_circular_or_not(struct node * head)
{
    struct node * ptr=head;
    do{
        ptr=ptr->next;
    }while(ptr!=NULL && ptr!=head);
    if(ptr==head)
        return 1;
    else 
        return 0;
}
int length_of_cll(struct node * head)
{
    int length=0;
    struct node * ptr=head;
    do{
        length++;
        ptr=ptr->next;
    }while(ptr!=NULL);
    return length;
}
struct node * swap_first_last(struct node * head)
{
    struct node *ptr=head;
    while(ptr->next!=head)
    {
        ptr=ptr->next;
    }
    head->data=head->data ^ ptr->data;
    ptr->data=head->data ^ ptr->data;
    head->data=head->data ^ ptr->data;
    return head;
}
int main()
{
    struct node * head=create_cll(1);
    head=append_node(head,2);
    head=append_node(head,3);
    head=swap_first_last(head);
    print_nodes(head);
    return 0;
}