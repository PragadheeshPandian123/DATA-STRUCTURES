# include <stdio.h>
# include <stdlib.h>
typedef struct node {
    int data;
    struct node * next;
} Node ;

Node * front=NULL,*rear=NULL;
void insert(){
    int data;
    printf("Enter the data: ");
    scanf("%d",&data);
    Node * temp=(Node *)malloc(sizeof(Node));
    temp->data=data;
    temp->next=NULL;
    if(front==NULL && rear==NULL){
        front=rear=temp;
    }
    else{
        rear->next=temp;
        rear=temp;
    }
}

void delete(){
    if(front==NULL && rear==NULL){
        printf("Underflow\n");
        return;
    }
    else {
        int val=front->data;
        Node* temp=front;
        front=front->next;
        printf(" The Deleted element is : %d \n",val);
        free(temp);
    }
}

void peek(){
    if(front==NULL && rear==NULL){
        printf("Underflow\n");
        return;
    }
    else{
        int val=rear->data;
        printf("The topmost element is : %d \n",val);
    }
}

void display(){
    if(front==NULL && rear==NULL){
        printf("Queue is Empty. \n");
        return;
    }
    else{
        Node * curr=front;
        while(curr!=NULL){
            printf("%d ",curr->data);
            curr=curr->next;
        }
        printf("\n");
    }
}

int main(){
    int choice;
    do{
        printf("Menu\n");
        printf("1. INSERT \n");
        printf("2. PEEK\n");
        printf("3. DELETE\n");
        printf("4. DISPLAY\n");
        printf("5. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                insert();break;
            case 2:
                peek();break;
            case 3:
                delete();break;
            case 4:
                display();break;
        }

        if(choice!=4 && choice !=5){
            printf("The Queue is : ");
            display();
        }
    }while(choice!=5);
    return 0;
}