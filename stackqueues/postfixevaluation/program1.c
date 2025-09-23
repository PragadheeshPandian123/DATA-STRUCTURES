# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <ctype.h>
# define MAX 10

int st[MAX],top=-1;

void push(int val){
    if(top==MAX-1){
        printf("OVERLFOW\n");
        exit(1);
    }
    st[++top]=val;
}

int pop(){
    if(top==-1){
        printf("UNDERFLOW\n");
        exit(1);
    }
    int val=st[top];
    top--;
    return val;
}

int postfixeval(char exp[]){
    int val;
    int n=strlen(exp);
    for(int i=0;i<n-1;i++){
        if(isdigit(exp[i])){
            int digit=0;
            while(!isspace(exp[i])){
                digit=digit*10 + (exp[i]-'0');
                i++;
            }
            push(digit);
        }
        else if(isspace(exp[i])){
            continue;
        }
        else{
            int op2=pop();
            int op1=pop();
            switch(exp[i]){
                case '+':
                    val=op1+op2;
                    break;
                case '-':
                    val=op1-op2;
                    break;
                case '*':
                    val=op1*op2;
                    break;
                case '/':
                    val=op1/op2;
                    break;
                case '%':
                    val=op1%op2;
                    break;
            }
            push(val);
        }
    }
    return pop();
}

int main(){
    char exp[50];
    printf("Enter postfix: ");
    fgets(exp,50,stdin);
    int val=postfixeval(exp);
    printf("The value is: %d",val);
    return 0;
}