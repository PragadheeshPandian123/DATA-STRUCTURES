# include <stdio.h>
# include <stdlib.h>
struct node 
{
    int data;
    struct node * next;
};
struct node * push_data(struct node * tail,int data)
{
    struct node * temp=(struct node * )malloc(sizeof(struct node));
    temp->data=data;
    temp->next=NULL;

    tail->next=temp;
    tail=temp;
    return tail;
}

struct node * sorted_intersect(struct node * headA, struct node * headB)
{
    struct node dummy;
    dummy.data=-1;
    dummy.next=NULL;
    struct node * tail=&dummy;

    while(headA!=NULL && headB!=NULL)
    {
        if(headA->data==headB->data)
        {
            tail=push_data(tail,headA->data);
            headA=headA->next;
            headB=headB->next;
        }
        else if(headA->data <headB->data)
        {
            headA=headA->next;
        }
        else
        {
            headB=headB->next;
        }
    }
    return dummy.next;
}
int main()
{
    
}