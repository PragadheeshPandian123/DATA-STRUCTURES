# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <ctype.h>
# define MAX 15

char st[MAX];
int top=-1;

int priority(char op){
    if(op=='*' || op=='/' || op=='%'){
        return 2;
    }
    if(op=='+' || op=='-'){
        return 1;
    }
}

void push(char ch){
    if(top==MAX-1){
        printf("OVERFLOW\n");
        exit(1);
    }
    top++;
    st[top]=ch;
}

char pop(){
    if(top==-1){
        printf("UNDERFLOW\n");
        exit(1);
    }
    char ch=st[top];
    top--;
    return ch;
}

void infixtoPostfix(char exp[]){
    int n=strlen(exp);
    char postfix[n+1];
    int k=0,i;
    for(i=0;i<n;i++){
        if(exp[i]=='('){
            push(exp[i]);
        }
        else if(exp[i]==')'){
            while(top!=-1 &&  st[top]!='('){
                postfix[k++]=pop();
            }
            if(top==-1){
                printf("INVALID EXPRESSION\n");
                exit(1);
            }
            pop();
        }

        else if(isalnum(exp[i])){
            postfix[k++]=exp[i];
        }
        else if(exp[i]=='+' || exp[i]=='-' || exp[i]=='*' || exp[i]=='/' || exp[i]=='%' ){
            if(top!=-1 && st[top]!='(' && priority(st[top])>=priority(exp[i])){
                postfix[k++]=pop();
            }
            push(exp[i]);
        }
        else if(exp[i]=='\n'){
            continue;
        }
        else{
            printf("Invalid Expression\n");
            exit(1);
        }
    }
    while(top!=-1 && st[top]!='('){
        postfix[k++]=pop();
    }
    postfix[k]='\0';
    printf("The postfix is: %s",postfix);
}

int main(){
    char exp[50];
    printf("Enter infix: ");
    fgets(exp,50,stdin);
    exp[strcspn(exp, "\n")] = '\0';
    infixtoPostfix(exp);
    return 0;
}