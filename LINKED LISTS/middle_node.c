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
int find_middle_node_1(struct node * head);
int find_middle_node_2(struct node * head);//Tortoise and Hare algorithm

int main()
{
    struct node * head=create_node(1);
    head=append_node(head,2);
    head=append_node(head,3);
    head=append_node(head,4);
    head=append_node(head,5);
    // head=append_node(head,6);
    
    // head=append_node(head,60);
    print_nodes(head);
    int mid_node=find_middle_node_2(head); 
    printf("\n%d\n",mid_node);   
    return 0;
}

int find_middle_node_1(struct node * head)
{
    int mid,length=0;
    struct node * ptr=head;
    while(ptr!=NULL)
    {
        length++;
        ptr=ptr->next;
    }
    mid=length/2;
    int index=0;
    ptr=head;
    while(index!=mid)
    {
        ptr=ptr->next;
        index++;
    }
    return ptr->data;
}
int find_middle_node_2(struct node * head)
{
    struct node * slow_ptr=head,*fast_ptr=head;
    while(fast_ptr!=NULL && fast_ptr->next!=NULL)
    {
        slow_ptr=slow_ptr->next;
        fast_ptr=fast_ptr->next->next;
    }
    return slow_ptr->data;
}