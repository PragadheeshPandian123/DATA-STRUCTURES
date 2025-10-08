# include <stdio.h>
# include <stdlib.h>


typedef struct node {
    int data;
    struct node * prev;
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
        printf("Delete the linked list first.\n");
        return;
    }
    Node * temp=(Node *)malloc(sizeof(Node));
    int data;
    printf("Enter the data: ");
    scanf("%d",&data);
    temp->data=data;
    temp->prev=temp;
    temp->next=temp;
    head=temp;
    printf("Linked List Successfully created.\n");

}

int length(){
    Node * curr=head;
    int length=0;
    if(head==NULL){
        return 0;
    }
    do{
       length++;
       curr=curr->next; 
    }while(curr!=head);
    return length;
}

void insert_at_begn(){

    if(head==NULL)
    {
        create_list();
        return;
    }
    int data;
    Node * temp=(Node *)malloc(sizeof(Node)),*curr=head;
    printf("Enter the data: \n");
    scanf("%d",&data);
    temp->data=data;
    while(curr->next!=head){
        curr=curr->next;
    }
    curr->next=temp;
    temp->prev=curr;
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
    while(curr->next!=head)
        curr=curr->next;
    curr->next=temp;
    temp->prev=curr;
    temp->next=head;
    head->prev=temp;
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
    temp->prev=curr;
    temp->next=curr->next;
    curr->next=temp;
    temp->next->prev=temp;
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
    if(head==NULL)
    {
        printf("Linked List is empty.\n");
        return;
    }
    Node * curr=head,*temp;
    while(curr->next!=head){
        curr=curr->next;
    }
    curr->next=head->next;
    head->next->prev=curr;
    temp=head;
    head=curr->next;
    free(temp);
    printf("Successfully Deleted.\n");
}


void delete_at_end()
{
    if(head==NULL)
    {
        printf("Linked List is empty.\n");
        return;
    }
    if(head->next==head)
    {
        Node *temp=head;
        free(temp);
        head=NULL;
        return;
    }
    Node *curr=head,*temp;
    while(curr->next->next!=head)
        curr=curr->next;
    temp=curr->next;
    curr->next=head;
    head->prev=curr;
    free(temp);
    printf("Successfully Deleted\n");
}

void delete_at_pos()
{
    if(head==NULL)
    {
        printf("Linked List is empty.\n");
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
    printf("Enter the position of the node to be updated(0 - %d): ",l-1);
    scanf("%d",&pos);
    printf("Enter the new data: ");
    scanf("%d",&data);
    if (pos <0 || pos >=l) {
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

void display_list()
{
    if(head==NULL)
    {
        printf("Empty Linked List.\n");
        return;
    }
    Node * curr=head;
    do{
        printf("%d ",curr->data);
        curr=curr->next;
    }while(curr!=head); 
    printf("\n");
}

void delete_list() {
    if (head == NULL) {
        printf("Empty Linked List.\n");
        return;
    }

    Node *curr = head, *temp;
    Node * start=head;
    do {
        temp = curr;
        curr = curr->next;
        free(temp);
    } while (curr != start);

    head = NULL;
    printf("List deleted successfully.\n");
}


void sort_list() {
    if (head == NULL) {
        printf("Empty Linked List. Create one first\n");
        return;
    }

    if (head->next == head) {
        printf("Linked List Already Sorted.\n");
        return;
    }

    printf("SORT MENU: \n");
    printf("1. ASCENDING\n");
    printf("2. DESCENDING\n");
    int choice;
    printf("Enter your choice: \n");
    scanf("%d", &choice);

    int swapped;
    Node *ptr1, *lptr = NULL;

    do {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != head && ptr1->next != lptr) {
            if ((choice == 1 && ptr1->data > ptr1->next->data) ||
                (choice == 2 && ptr1->data < ptr1->next->data)) {

                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);

    printf("Linked List Successfully sorted.\n");
}

void reverse_list() {
    if (head == NULL) {
        printf("Empty Linked List. Create one first\n");
        return;
    }

    if (head->next == head) { 
        printf("List reversed successfully (only one node).\n");
        return;
    }

    Node *current = head;
    Node *temp = NULL;

    do {
        temp = current->next;
        current->next = current->prev;
        current->prev = temp;
        current = temp; 
    } while (current != head);

    head = head->next;

    printf("List reversed successfully.\n");
}


