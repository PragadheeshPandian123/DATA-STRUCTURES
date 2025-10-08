# include <stdio.h>
# include <stdlib.h>
# include "functions.h"

int main(){
    int choice;
    do{
        printf("MENU\n");
        printf("1. CREATE STACK\n");
        printf("2. PUSH\n");
        printf("3. POP\n");
        printf("4. PEEK\n");
        printf("5. DISPLAY\n");
        printf("6. DELETE STACK\n");
        printf("7. QUIT\n");
        printf("Enter your choice (1-7): ");
        scanf("%d",&choice);

        switch(choice){
            case 1: create_stack();break;
            case 2: push();break;
            case 3: pop();break;
            case 4: peek();break;
            case 5: display();break;
            case 6: delete_stack();break;
        }

        if(choice!=5 && choice !=7){
            printf("Stack after operation: \n");
            display();
        }
    }while(choice!=7);
}

