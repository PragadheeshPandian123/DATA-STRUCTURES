# include <stdio.h>
# include <stdlib.h>

typedef struct node {
    int data;
    struct node * next;
}Node;

Node * creatLinkedList(Node * head,int val){
    if(head!=NULL){
        printf("Linked List Already created \n");
        return head;
    }
    Node * newNode=(Node *)malloc(sizeof(Node));
    newNode->data=val;
    newNode->next=NULL;
    head=newNode;
    return head;
}

int length(Node * head){
    Node * curr=head;
    int n=0;
    while(curr!=NULL){
        n=n+1;
        curr=curr->next;
    }
    return n;
}


Node * insertAtBeginning(Node * head){
    int data;
    printf("Enter the data: ");
    scanf("%d",&data);
    if(head==NULL)
    {
        return creatLinkedList(head,data);
    }
    else{
        Node * newNode=(Node *)malloc(sizeof(Node));        
        newNode->data=data;
        newNode->next=head;
        head=newNode;
        return head;
    }
}

Node * insertAtEnd(Node * head){
    if(head==NULL){
        int data;
        printf("Enter the data: ");
        scanf("%d",&data);
        return creatLinkedList(head,data);
    }
    else {
        Node * curr=head;
        while(curr->next!=NULL){
            curr=curr->next;
        }
        int data;
        printf("Enter the data: ");
        scanf("%d",&data);
        Node * newNode = (Node *)malloc(sizeof(Node));
        newNode->data=data;
        newNode->next=NULL;
        curr->next=newNode;
        return head;
    }
}


Node * insertAtMiddle(Node * head,int pos){
    if(head==NULL)
    {
        int data;
        printf("Enter the data: ");
        scanf("%d",&data);
        return creatLinkedList(head,data);
    }
    else{
        if(pos==0){
            return insertAtBeginning(head);
        }
        else if(pos==length(head)){
            return insertAtEnd(head);
        }
        else if(pos < 0 || pos > length(head)){
            printf("Invalid Node \n");
            return head;
        }
        else{
            int data;
            printf("Enter the data: ");
            scanf("%d",&data);
            int i=0;
            Node * curr=head;
            while(i<pos-1){
                curr=curr->next;
                i++;
            }
            Node * newNode = (Node *)malloc(sizeof(Node));
            newNode->data=data;
            newNode->next=curr->next;
            curr->next=newNode;
            return head;
        }
    }
}


Node * deleteAtBeginning(Node * head){
    if(head==NULL){
        printf("Linked List Empty\n");
        return NULL;
    }
    else{
        Node * temp=head;
        head=head->next;
        free(temp);
        return head;
    }
}

Node * deleteAtEnd(Node * head){
    if(head==NULL){
        printf("Linked List Empty \n");
        return  NULL;
    }
    else if(head->next==NULL){
        free(head);
        return NULL;
    }
    else{
        Node * curr=head;
        while(curr->next->next!=NULL){
            curr=curr->next;
        }
        Node * temp=curr->next;
        free(temp);
        curr->next=NULL;
        return head;
    }
}

Node * deleteAtMiddle(Node * head,int pos){
    if(head==NULL){
        printf("Linked List Empty \n");
        return  NULL;
    }
    else if(head->next=NULL){
        free(head);
        return NULL;
    }
    else{
        if(pos==0){
            return deleteAtBeginning(head);
        }
        else if(pos==length(head)-1){
            return deleteAtEnd(head);
        }
        else if(pos < 0 || pos >=length(head)){
            printf("Invalid Node \n");
            return head;
        }
        else{
            int i=0;
            Node * curr=head;
            while (i< pos-1){
                curr=curr->next;
                i++;
            }
            Node * temp=curr->next;
            curr->next=temp->next;
            free(temp);
            return head;
        }
    }
}

Node * sortLinkedList(Node * head){
    if(head==NULL){
        printf("Empty Linked List. \n");
        return NULL;
    }
    if(head->next==NULL){
        printf("Linked List Already sorted. \n");
        return head;
    }
    else
    {
        Node * ptr1,*ptr2=NULL;
        int flag=0;
        do{
            flag=0;
            ptr1=head;
            while(ptr1->next!=ptr2){
                if(ptr1->data > ptr1->next->data){
                    flag=1;
                    int temp=ptr1->data;
                    ptr1->data=ptr1->next->data;
                    ptr1->next->data=temp;
                }
                ptr1=ptr1->next;
            }
            ptr2=ptr1;
        }while(flag);
    }
}