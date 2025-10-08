# include <stdio.h>
# include <stdlib.h>
# include "functions.h"

Node * create_node (int coeff ,int pow){
    Node * temp=(Node *)malloc(sizeof(Node));
    temp->coeff=coeff;
    temp->pow=pow;
    temp->next=NULL;
    return temp;
}
Node * append_node(Node * head,int coeff,int pow){
    if(head==NULL){
        head=create_node(coeff,pow);
        return head;
    }
    else{
        Node *curr=head;
        while(curr->next!=NULL){
            curr=curr->next;
        }
        Node * temp=create_node(coeff,pow);
        curr->next=temp;
        return head;
    }
}

Node * add_poylnomials(Node * head1,Node * head2){
    Node * result=NULL;
    Node * curr1=head1,*curr2=head2,*curr3=result;
    int sum_coeff=0;
    while(curr1!=NULL && curr2!=NULL){
        if(curr1->pow > curr2->pow){
            result=append_node(result,curr1->coeff,curr1->pow);
            curr1=curr1->next;
        }
        else if(curr2->pow>curr1->pow){
            result=append_node(result,curr2->coeff,curr2->pow);
            curr2=curr2->next;
        }
        else{
            sum_coeff=curr1->coeff+curr2->coeff;
            result=append_node(result,sum_coeff,curr1->pow);
            curr1=curr1->next;
            curr2=curr2->next;            
        }   
    }
    if(curr1==NULL){
        while(curr2!=NULL){
            result=append_node(result,curr2->coeff,curr2->pow);
            curr2=curr2->next;
        }
    }
    if(curr2==NULL){
        while(curr1!=NULL){
            result=append_node(result,curr1->coeff,curr1->pow);
            curr1=curr1->next;
        }
    }
    return result;
}

void display_polynomial(Node * head){
    Node * curr=head;
    if(curr==NULL){
        printf("0 x 0\n");
    }
    while(curr->next!=NULL){
        printf("%d x %d + ",curr->coeff,curr->pow);
        curr=curr->next;
    }
    printf("%d x %d \n",curr->coeff,curr->pow);
}
