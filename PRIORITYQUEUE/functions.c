# include <stdio.h>
# include <stdlib.h>

typedef struct node {
    int data;
    struct node * next;
    int prioritynum;
}Node;

Node *insertPQ(Node * head,int data,int pnum)
{
    if(head==NULL){
        Node * newNode=(Node *)malloc(sizeof(Node));
        newNode->data=data;
        newNode->prioritynum=pnum;
        newNode->next=NULL;
        head=newNode;   
        printf("Value inserted in the priority Queue successfully \n");
        return head;
    }
    else{
        Node * newNode=(Node *)malloc(sizeof(Node));
        newNode->data=data;
        newNode->prioritynum=pnum;
        Node * curr=head,*prev=NULL;
        while(curr!=NULL && curr->prioritynum<=pnum){
            prev=curr;
            curr=curr->next;
        }
        if (prev == NULL) {
            newNode->next = head;
            head = newNode;
        }
        else {
            prev->next = newNode;
            newNode->next = curr;
        }
        printf("Value inserted in the priority Queue successfully \n");
        return head;
    }
}

Node * deletePQ(Node * head)
{
    if(head==NULL){
        printf("UNDERFLOW \n");
        return NULL;
    }
    else{
        Node * temp=head;
        head=head->next;
        int val=temp->data;
        int pnum=temp->prioritynum;
        free(temp);
        printf("The deleted Node is : (%d,%d) \n",val,pnum);
        return head;
    }
}

void displayPQ(Node * head){
    if(head==NULL){
        printf("Empty Priority Queue\n");
    }
    else{
        Node * curr=head;
        while(curr->next!=NULL){
            printf("(%d,%d) -> ",curr->data,curr->prioritynum);
            curr=curr->next;
        }
        printf("(%d,%d)\n",curr->data,curr->prioritynum);
    }
}