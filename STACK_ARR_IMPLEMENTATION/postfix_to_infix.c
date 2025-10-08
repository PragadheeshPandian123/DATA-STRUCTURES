# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <ctype.h>
int prec(char ch){
    if (ch=='^')   return 3;
    else if(ch=='*' || ch=='/') return 2;
    else if(ch=='+' || ch=='-') return 1;
    else return 0;
}

void infix_to_postfix(char * exp){
    int length=strlen(exp);
    char result[length+1];
    char stack[length];
    int top=-1;
    int k=0;
    for(int i=0;i<length;i++){
        if(isalnum(exp[i])){
            result[k++]=exp[i];
        }
        else if(exp[i]=='('){
            stack[++top]=exp[i];
        }
        else if(exp[i]==')'){
            while(top!=-1 && stack[top]!='('){
                result[k++]=stack[top--];
            }
            if(top!=-1)
                top--;
        }
        else {
            while(top!=-1 && (prec(exp[i])<prec(stack[top])||prec(exp[i])==prec(stack[top]))){
                result[k++]=stack[top--];
            }
            stack[++top]=exp[i];
        }
    }
    while(top!=-1){
        result[k++]=stack[top--];
    }
    result[k]='\0';
    printf("POSTFIX: %s\n",result);
}

int main(){
    char exp[100];
    printf("Enter a infix expression: ");
    fgets(exp,100,stdin);
    printf("INFIX : %s\n",exp);
    infix_to_postfix(exp);
    return 0;
}