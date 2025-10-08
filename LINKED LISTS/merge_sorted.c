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
struct node * push_data(struct node * tail,int data)
{
    struct node * temp=(struct node * )malloc(sizeof(struct node));
    temp->data=data;
    temp->next=NULL;

    tail->next=temp;
    tail=temp;
    return tail;
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
struct node * merge_sorted(struct node * headA,struct node * headB)
{
    struct node dummy;
    dummy.data=-1;
    dummy.next=NULL;
    struct node * tail=&dummy;
    while(headA!=NULL &&  headB!=NULL)
    {
        if(headA->data < headB->data)
        {
            tail=push_data(tail,headA->data);
            headA=headA->next;
        }
        else if(headA->data > headB->data)
        {
            tail=push_data(tail,headB->data);
            headB=headB->next;
        }
        else
        {
            tail=push_data(tail,headA->data);
            tail=push_data(tail,headB->data);
            headA=headA->next;
            headB=headB->next;
        }
    }
    if(headA==NULL)
    {
        while(headB!=NULL)
        {
            tail=push_data(tail,headB->data);
            headB=headB->next;
        }
    }
    else 
    {
        while(headA!=NULL)
        {
            tail=push_data(tail,headA->data);
            headA=headA->next;
        }
    }
    return dummy.next;
}

int main()
{
    struct node * headA,*headB;
    headA=create_node(1);
    headA=append_node(headA,1);
    headA=append_node(headA,4);
    // headA=append_node(headA,40);
    printf("\nA: \n");
    print_nodes(headA);
    headB=create_node(1);
    headB=append_node(headB,2);
    headB=append_node(headB,4);
    headB=append_node(headB,6);

    printf("\nB: \n");
    print_nodes(headB);

    struct node * merge=merge_sorted(headA,headB);
    printf("\n Merge: \n");
    print_nodes(merge);
    return 0;
}