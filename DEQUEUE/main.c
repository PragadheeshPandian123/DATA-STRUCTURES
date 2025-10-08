#include <stdio.h>
# include "functions.c"
#define MAX 10

int main()
{
    int option;
    printf("\n *****MAIN MENU*****");
    printf("\n 1.Input restricted deque");
    printf("\n 2.Output restricted deque");
    printf("\n Enter your option : ");
    scanf("%d", &option);
    switch (option)
    {
        case 1:
            input_deque();
            break;
        case 2:
            output_deque();
            break;
        default:
            printf("\n Invalid option");
    }
    return 0;
}

