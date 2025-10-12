# include <stdio.h>
# include "functions.c"
Node * head=NULL;
int main()
{
    printf("==========  Priority Queue ======== \n");
    printf(" 1.Insert \n 2.Delete \n 3.Display \n 4.Exit \n");
    int choice,val,pnum;
    do
    {
        printf("Enter Choice : ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("Enter value and priority value: ");
            scanf("%d %d",&val,&pnum);
            head=insertPQ(head,val,pnum);
            break;
        case 2:
            head=deletePQ(head);
            break;
        case 3:
            printf("The priority Queue is : \n");
            displayPQ(head);
            break;
        case 4:
            printf("Exiting...");
            break;
        default:
            printf("Invalid Choice!Try Again \n");
            break;
        }
    } while (choice!=4);
    return 0;
}