# include <stdio.h>
# include <stdlib.h>
# include "functions.h"

Node * head=NULL;

void create_list()
{
    if(head!=NULL)
    {
        printf("Deleting the Linked list...\n");
        delete_list();
    }
    int data;
    Node * temp=(Node *)malloc(sizeof(Node));
    printf("Enter the data: \n");
    scanf("%d",&data);
    temp->data=data;
    temp->next=NULL;
    head=temp;
    printf("Linked List Successfully created.\n");
}

int length()
{
    Node * curr=head;
    int length=0;
    while(curr!=NULL){
        length++;
        curr=curr->next;
    }
    return length;
}

void insert_at_begn(){

    if(head==NULL)
    {
        create_list();
        return;
    }
    int data;
    Node * temp=(Node *)malloc(sizeof(Node));
    printf("Enter the data: \n");
    scanf("%d",&data);
    temp->data=data;
    temp->next=head;
    head=temp;
    printf("Successfully inserted.\n");
}

void insert_at_end()
{
    if(head==NULL)
    {
        create_list();
        return;
    }
    int data;
    Node * temp=(Node *)malloc(sizeof(Node)),*curr;
    printf("Enter the data: \n");
    scanf("%d",&data);
    temp->data=data;
    curr=head;
    while(curr->next!=NULL)
        curr=curr->next;
    curr->next=temp;
    temp->next=NULL;
    printf("Successfully inserted\n");

}

void insert_at_pos()
{
    if(head==NULL)
    {
        create_list();
        return;
    }
    int data,pos;
    printf("Enter the data: \n");
    scanf("%d",&data);
    int l=length();
    printf("Enter the pos (1-%d):",l+1);
    scanf("%d",&pos);
    pos--;
    if(pos==0)
    {
        insert_at_begn();
        return;
    }
    else if(pos==l)
    {
        insert_at_end();
        return;
    }
    Node * curr=head;
    int i=0;
    while(i<pos)
    {
        curr=curr->next;
        i++;
    }
    Node * temp=(Node *)malloc(sizeof(Node));
    temp->data=data;
    temp->next=curr->next;
    curr->next=temp;
    printf("Successfully inserted\n");

}

void insert_after()
{
    if(head==NULL)
    {
        printf("Empty Linked List.Create one first\n");
        create_list();
        return;
    }
    else if(head->next==NULL)
    {
        printf("Linked List has only one node\n.Inserting at the end...\n");
        insert_at_end();
        return;
    }
    int data1,data2;
    Node * temp=(Node *)malloc(sizeof(Node));
    printf("Enter the Value of the node after which a new node is to be inserted.\n");
    scanf("%d",&data1);
    printf("Enter the data: ");
    scanf("%d",&data2);
    temp->data=data2;
    Node * curr=head;
    while(curr->data!=data1)
        curr=curr->next;
    temp->next=curr->next;
    curr->next=temp;
    printf("Successfully inserted\n");
}

void insert_before()
{
    if(head==NULL)
    {
        printf("Empty Linked List.Create one first\n");
        create_list();
        return;
    }
    else if(head->next==NULL)
    {
        printf("Linked List has only one node\n.Inserting at beginning...\n");
        insert_at_begn();
        return;
    }
    int data1,data2;
    Node * temp=(Node *)malloc(sizeof(Node));
    printf("Enter the Value of the node before which a new node is to be inserted.\n");
    scanf("%d",&data1);
    printf("Enter the data: ");
    scanf("%d",&data2);
    temp->data=data2;
    Node * curr=head;
    while(curr->next->data!=data1)
        curr=curr->next;
    temp->next=curr->next;
    curr->next=temp;
    printf("Successfully inserted\n");
}

void insert_node()
{
    int choice,pos;
    printf("INSERT MENU \n");
    printf("1. AT BEGINING\n");
    printf("2. AT MIDDLE\n");
    printf("3. AT END\n");
    printf("4. AFTER A NODE: \n");
    printf("5. BEFORE A NODE: \n");
    printf("Enter your choice (1-5): ");
    scanf("%d",&choice);
    if(choice==1)
        insert_at_begn();
    else if(choice==3)
        insert_at_end();
    else if(choice==2)
        insert_at_pos();
    else if(choice==4)
        insert_after();
    else if(choice==5)
        insert_before();
    else  
        printf("Invalid Choice\n");
    return;
}

void delete_at_begn()
{
    if(head==NULL)
    {
        printf("Linked List is empty.\nCreate One First\n");
        create_list();
        return;
    }
    Node * temp=head;
    head=head->next;
    free(temp);
    printf("Successfully Deleted.\n");
}

void delete_at_end()
{
    if(head==NULL)
    {
        printf("Linked List is empty.\nCreate One First\n");
        create_list();
        return;
    }
    if(head->next==NULL)
    {
        Node *temp=head;
        free(temp);
        head=NULL;
    }
    Node *curr=head,*temp;
    while(curr->next->next!=NULL)
        curr=curr->next;
    temp=curr->next;
    curr->next=NULL;
    free(temp);
    printf("Successfully Deleted\n");
}

void delete_at_pos()
{
    if(head==NULL)
    {
        create_list();
        return;
    }
    int pos;
    int l=length();
    printf("Enter the pos (0-%d):",l-1);
    scanf("%d",&pos);
    pos--;
    if(pos==0)
    {
        delete_at_begn();
        return;
    }
    else if(pos==l-1)
    {
        delete_at_end();
        return;
    }
    Node * curr=head;
    int i=0;
    while(i<pos-1)
    {
        curr=curr->next;
        i++;
    }
    Node * temp=curr->next;
    curr->next=temp->next;
    free(temp);
    printf("Successfully Deleted\n");
}

void delete_after()
{
    if(head==NULL)
    {
        printf("Empty Linked List.Create one first\n");
        create_list();
        return;
    }
    else if(head->next==NULL)
    {
        printf("Linked List has only one node\n.Deleting it...\n");
        Node *temp=head;
        free(temp);
        head=NULL;
        printf("Successfully Deleted.\n");
        return;
    }
    Node * temp,*curr;
    int data;
    printf("Enter the Value of the node after which a  node is to be deleted.\n");
    scanf("%d",&data);
    curr=head;
    while(curr->data!=data)
        curr=curr->next;
    temp=curr->next;
    curr->next=curr->next->next;
    free(temp);
    printf("Successfully deleted\n");
}

void delete_before()
{
    if(head==NULL)
    {
        printf("Empty Linked List.Create one first\n");
        create_list();
        return;
    }
    else if(head->next==NULL)
    {
        printf("Linked List has only one node\n.Deleting it...\n");
        Node *temp=head;
        free(temp);
        head=NULL;
        printf("Successfully Deleted.\n");
        return;
    }
    int data;
    Node * temp,*curr;
    printf("Enter the Value of the node before which a node is to be deleted.\n");
    scanf("%d",&data);
    curr=head;
    while(curr->next->data!=data)
        curr=curr->next;
    temp=curr->next;
    curr->next=temp->next;
    free(temp);
    printf("Successfully Deleted\n");
}

void delete_node()
{
    int choice,pos;
    printf("DELETE MENU \n");
    printf("1. AT BEGINING\n");
    printf("2. AT MIDDLE\n");
    printf("3. AT END\n");
    printf("4. AFTER A NODE: \n");
    printf("5. BEFORE A NODE: \n");
    printf("Enter your choice (1-5): ");
    scanf("%d",&choice);
    if(choice==1)
        delete_at_begn();
    else if(choice==3)
        delete_at_end();
    else if(choice==2)
        delete_at_pos();
    else if(choice==4)
        delete_after();
    else if(choice==5)
        delete_before();
    else  
        printf("Invalid Choice\n");
    return;
}

void update()
{
    if(head==NULL)
    {
        printf("Empty Linked List.Create one first\n");
        create_list();
        return;
    }
    int data,pos;
    printf("Enter the position of the node to be deleted : ");
    scanf("%d",&pos);
    printf("Enter the new data: ");
    scanf("%d",&data);
    int l = length();
    if (pos <= 0 || pos > l) {
        printf("Invalid position. Valid range is 1 to %d\n", l);
        return;
    }
    pos--;
    int i=0;
    Node * curr=head;
    while(i<pos)
        curr=curr->next;
    curr->data=data;
    printf("Successfully Updated.\n");
}

void sort_list()
{

    if(head==NULL)
    {
        printf("Empty Linked List.Create one first\n");
        create_list();
        return;
    }       
    if(head->next==NULL)
    {
        printf("Linked List Already Sorted.\n");
        return;
    }
    printf("SORT MENU: \n");
    printf("1. ASCENDING\n");
    printf("2. DESCENDING\n");
    int choice;
    printf("Enter your choice: \n");
    scanf("%d",&choice);
    int swapped;
    Node *ptr1, *ptr2 = NULL;

    do {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != ptr2) {
            if ((choice==1 && ptr1->data > ptr1->next->data)||(choice==2 && ptr1->data < ptr1->next->data)) {
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;

                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        ptr2 = ptr1;  
    } while (swapped);

    printf("Linked List Successfully sorted.\n");

}

void reverse_list()
{
    if(head==NULL)
    {
        printf("Empty Linked List.Create one first\n");
        create_list();
        return;
    }
    Node * prev=NULL,*curr=head,*next=head;
    while(next!=NULL)
    {
        next=next->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    head=prev;
    printf("Successfully Reversed.\n");
}

void delete_list()
{
    if(head==NULL)
    {
        printf("Empty Linked List.Create one first\n");
        create_list();
        return;
    }
    Node *curr=head,*temp;
    while(curr!=NULL)
    {
        temp=curr;
        curr=curr->next;
        free(temp);
    }
    printf("Successfully Deleted.\n");
}

void display_list()
{
    if(head==NULL)
    {
        printf("Empty Linked List.Create one first\n");
        create_list();
        return;
    }
    Node * curr=head;
    while(curr!=NULL)
    {
        printf("%d ",curr->data);
        curr=curr->next;
    }
    printf("\n");
}