#ifndef FUNCTIONS_H
#define FUNCTIONS_H

typedef struct node {
    int coeff;
    int pow;
    struct node * next;
} Node ;

Node * create_node (int coeff ,int pow);
    
Node * append_node(Node * head,int coeff,int pow);

Node * add_poylnomials(Node * head1,Node * head2);

void display_polynomial(Node * head);

#endif
