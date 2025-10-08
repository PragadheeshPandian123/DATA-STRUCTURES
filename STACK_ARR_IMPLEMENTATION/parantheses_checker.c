# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# define MAX 10
int top=-1;
char stack[MAX];
void push(char);
char pop();
int main(){
    char exp[MAX],temp;
    int i,flag=1;
    printf("Enter the expression: ");
    fgets(exp,MAX,stdin);

    for(i=0;i<strlen(exp);i++){
        if(exp[i]=='{' || exp[i]=='[' || exp[i]=='('){
            push(exp[i]);
        }
        else if(exp[i]=='}' || exp[i]==']' || exp[i]==')'){
            if(top==-1)
                flag=0;
            else{
                temp=pop();
                if(exp[i]=='}' && (temp=='[' || temp=='(')){
                    flag=0;
                }
                else if(exp[i]==']' && (temp=='{' || temp== '(')){
                    flag=0;
                }
                else if(exp[i]==')' && (temp=='{' || temp== '[')){
                    flag=0;
                }
            }
        }
    }
    if(top>=0){
        flag=0;
    }
    if(flag==1){
        printf("\nValid expression\n");
    }
    else{
        printf("\nInvalid expression\n");
    }
    return 0;
}

void push(char ch){
    if(top==MAX-1){
        printf("Stack Overflow\n");
    }
    else{
        stack[++top]=ch;
    }
}
char pop(){
    if(top==-1){
        printf("\nUnderflow Error\n");
    }
    else{
        return stack[top--];
    }
}
