# include <stdio.h>
# define MAX 10

void insert();
void peek();
void delete();
void display();

int queue[MAX];
int rear=-1;
int front=-1;
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

void insert(){
    if(front==MAX-1){
        printf("OVERFLOW\n");
        return;
    }
    else if(front=-1 && rear==-1){
        front=rear=0;
    }
    else{
        rear++;
    }
    int data;
    printf("Enter the value: ");
    scanf("%d",&data);

    queue[rear]=data;
}

void delete(){
    if(front==-1 || front > rear){
        printf(" UNDERFLOW\n");
        return;
    }
    else{
        int val=queue[front];
        front++;
        printf("The element deleted is : %d",val);
        if(front>rear)
            front=rear=-1;
    }
}

void peek(){
    if(front==-1 || front > rear){
        printf("UNDERFLOW\n");
        return;
    }
    else{
        int val=queue[rear];
        printf("The value of topmost element is : %d",val);
    }
}

void display(){
    if(front == -1 || front > rear){
        printf("The queue is empty\n");
        return;
    }
    else{
        for(int i=front;i<=rear;i++){
            printf("%d ",queue[i]);
        }
    }
}