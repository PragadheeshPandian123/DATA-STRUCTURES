# include <stdio.h>
# include <stdlib.h>
struct node
{
    char url[50];
    struct node * next;
};

struct node * head=NULL;
struct node * vist_url(char []);
struct node * forward(int );
struct node * back(int);

int main()
{
    int choice,steps;
    char url[50];

    do{
        printf("\nMain Menu\n");
        printf("\n1.Visit(url)");
        printf("\n2.forward(steps)");
        printf("\n3.back(steps)");
        printf("\n4.Quit");
        printf("\n\nEnter Choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("Enter the url: ");
                scanf("%[^\n]s",url);
                head=visit_url(url);
                break;
            case 2:
                printf("Enter steps: ");
                scanf("%d",&steps);
                head=forward(steps);
                break;
            case 3:
                printf("Enter steps: ");
                scanf("%d",&steps);
                head=back(url);
                break;
        }
    }while(choice!=4);
}