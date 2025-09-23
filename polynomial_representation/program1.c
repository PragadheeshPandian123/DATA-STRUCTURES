# include <stdio.h>
# include <stdlib.h>
# include "functions.h"

int main(){
    Node * head1=NULL,*head2=NULL,*head3=NULL;
    int pow,coeff,choice;
    printf("Enter Polynomial 1: \n");
    do{
        printf("Enter the power of the term: ");
        scanf("%d",&pow);
        printf("Enter the coeff of the term: ");
        scanf("%d",&coeff);
        head1=append_node(head1,coeff,pow);
        printf("To continue enter 1 else enter 0: ");
        scanf("%d",&choice);
    }while(choice!=0);

    printf("Polynomial 1: ");
    display_polynomial(head1);

    printf("Enter Polynomial 2: \n");
    do{
        printf("Enter the power of the term: ");
        scanf("%d",&pow);
        printf("Enter the coeff of the term: ");
        scanf("%d",&coeff);
        head2=append_node(head2,coeff,pow);
        printf("To continue enter 1 else enter 0: ");
        scanf("%d",&choice);
    }while(choice!=0);

    printf("Polynomial 2: ");
    display_polynomial(head2);

    head3=add_poylnomials(head1,head2);
    printf("Added Polynomial : ");
    display_polynomial(head3);
    return 0;
}