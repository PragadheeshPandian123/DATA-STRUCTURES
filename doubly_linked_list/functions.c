# include <stdio.h>
# include <stdlib.h>

typedef struct node {
    struct node * prev;
    int data;
    struct node* next;
} Node;

void create_list();
int length();
void insert_at_begn();
void insert_at_end();
void insert_at_pos();
void insert_node();
void delete_at_begn();
void delete_at_end();
void delete_at_pos();
void delete_node();
void update();
void sort_list();
void reverse_list();
void delete_list();
void display_list();



Node * head=NULL;
void create_list(){
    if(head!=NULL){
        printf("Delete the list first.\n");
        return;
    }
    int data;
    Node * temp=(Node *)malloc(sizeof(Node));
    printf("Enter data: ");
    scanf("%d",&data);
    temp->data=data;
    temp->prev=NULL;
    temp->next=NULL;
    head=temp;
    printf("Linked List successfully created.\n");
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

void display_list(){
    if(head==NULL){
        printf("Empty Linked List\n");
        return;
    }
    Node * curr=head;
    while(curr!=NULL){
        printf("%d ",curr->data);
        curr=curr->next;
    }
    printf("\n");
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
    temp->prev=NULL;
    temp->next=head;
    head->prev=temp;
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
    temp->prev=curr;
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
    int l=length();
    printf("Enter the pos (0-%d):",l);
    scanf("%d",&pos);
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
    printf("Enter the data: \n");
    scanf("%d",&data);
    Node * curr=head;
    int i=0;
    while(i<pos-1)
    {
        curr=curr->next;
        i++;
    }
    Node * temp=(Node *)malloc(sizeof(Node));
    temp->data=data;
    temp->next=curr->next;
    temp->prev=curr;
    curr->next->prev=temp;
    curr->next=temp;
    printf("Successfully inserted\n");

}

void insert_node()
{
    int choice,pos;
    printf("INSERT MENU \n");
    printf("1. AT BEGINING\n");
    printf("2. AT POSITION\n");
    printf("3. AT END\n");
    printf("Enter your choice (1-3): ");
    scanf("%d",&choice);
    if(choice==1)
        insert_at_begn();
    else if(choice==3)
        insert_at_end();
    else if(choice==2)
        insert_at_pos();
    else  
        printf("Invalid Choice\n");
}

void delete_at_begn()
{
    Node * temp;
    if(head==NULL)
    {
        printf("Linked List is empty.\nCreate One First\n");
        return;
    }
    if(head->next==NULL)
    {
        temp=head;
        free(temp);
        head=NULL;
        return;
    }
    temp=head;
    head=head->next;
    head->prev=NULL;
    free(temp);
    printf("Successfully Deleted.\n");
}

void delete_at_end()
{
    if(head==NULL)
    {
        printf("Linked List is empty.\nCreate One First\n");
        return;
    }
    if(head->next==NULL)
    {
        Node *temp=head;
        free(temp);
        head=NULL;
        return;
    }
    Node *curr=head,*temp;
    while(curr->next!=NULL)
        curr=curr->next;
    temp=curr;
    curr->prev->next=NULL;
    free(temp);
    printf("Successfully Deleted\n");
}

void delete_at_pos()
{
    if(head==NULL)
    {
        printf("Linked List is empty.\nCreate One First\n");
        return;
    }
    int pos;
    int l=length();
    printf("Enter the pos (0-%d):",l-1);
    scanf("%d",&pos);
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
    temp->next->prev=curr;
    free(temp);
    printf("Successfully Deleted\n");
}

void delete_node()
{
    int choice,pos;
    printf("DELETE MENU \n");
    printf("1. AT BEGINING\n");
    printf("2. AT POSITION\n");
    printf("3. AT END\n");
    printf("Enter your choice (1-3): ");
    scanf("%d",&choice);
    if(choice==1)
        delete_at_begn();
    else if(choice==3)
        delete_at_end();
    else if(choice==2)
        delete_at_pos();
    else  
        printf("Invalid Choice\n");
}


void update()
{
    if(head==NULL)
    {
        printf("Empty Linked List.Create one first\n");
        return;
    }
    int data,pos;
    int l = length();
    printf("Enter the position of the node to be updated (0-%d): ",l-1);
    scanf("%d",&pos);
    printf("Enter the new data: ");
    scanf("%d",&data);
    if (pos < 0 || pos >=l) {
        printf("Invalid position. Valid range is 0 to %d\n", l-1);
        return;
    }
    int i=0;
    Node * curr=head;
    while(i<pos){
        curr=curr->next;
        i++;
    }
    curr->data=data;
    printf("Successfully Updated.\n");
}

void sort_list()
{

    if(head==NULL)
    {
        printf("Empty Linked List.Create one first\n");
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

void reverse_list(){
    if(head==NULL)
    {
        printf("Empty Linked List.Create one first\n");
        return;
    }
    Node * prev,*curr;
    prev=NULL;
    curr=head;
    while(curr!=NULL){
        prev=curr->prev;
        curr->prev=curr->next;
        curr->next=prev;
        curr=curr->prev;
    }
    if(prev!=NULL)
        head=prev->prev;
    printf("Successfully Reversed\n");
}
void delete_list(){
    if(head==NULL)
    {
        printf("Empty Linked List.\n");
        return;
    }
    Node *curr=head,*temp;
    while(curr!=NULL)
    {
        temp=curr;
        curr=curr->next;
        free(temp);
    }
    head=NULL;
    printf("Successfully Deleted.\n");
}