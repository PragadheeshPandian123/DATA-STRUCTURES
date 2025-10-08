# include <stdio.h>
# include <stdlib.h>
# include "functions.c"
int main(){
    int choice;
    do{
        printf("1.Push\n2.Pop\n3.Peek\n4.Display\n5.Quit");
        printf("\nEnter: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
        }
        if(choice!=5){
            display();
        }
    }while(choice!=5);
    return 0;
}

