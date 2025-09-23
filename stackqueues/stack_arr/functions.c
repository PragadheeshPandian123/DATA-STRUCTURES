# include <stdio.h>
# include <stdlib.h>
# define MAX 10
int st[MAX],top=-1;
void push(){
    if(top==MAX-1){
        printf("OVERFLOW\n");
        return;
    }
    else{
        int val;
        printf("Enter val: ");
        scanf("%d",&val);
        top++;
        st[top]=val;
    }
}

void pop(){
    if(top==-1){
        printf("UNDERFLOW\n");
        return;
    }
    else{
        int val=st[top];
        top--;
        printf("Popped value is: %d",val);
    }
}

void peek(){
    if(top==-1){
        printf("Stack Empty\n");
        return;
    }
    else{
        int val=st[top];
        printf("The topmost element is : %d",val);
    }
}

void display(){
    if(top==-1){
        printf("Stack EMpty\n");
        return;
    }
    else{
        printf("The Stack is: \n");
        for(int i=top;i>=0;i--){
            printf("%d ",st[i]);
        }
        printf("\n");
    }
}