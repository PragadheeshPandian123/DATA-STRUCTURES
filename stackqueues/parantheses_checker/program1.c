# include <stdio.h>
# define MAX 10

char st[MAX];
int top=-1;

void push(char val){
    if(top==MAX-1){
        printf("OVERFLOW\n");
        return;
    }
    top++;
    st[top]=val;
}

char pop(){
    if(top==-1){
        printf("UNDERFLOW\n");
        return -1;
    }
    char val=st[top];
    top--;
    return val;
}

int main()
{
    char exp[50];
    printf("Enter expression: ");
    fgets(exp,50,stdin);
    int i=0;
    int flag=1;
    while(exp[i]!='\0'){
        if(exp[i]=='(' || exp[i]=='{' || exp[i]=='['){
            push(exp[i]);
        }
        else if(exp[i]==')' || exp[i]=='}' || exp[i]==']'){
            if(top==-1){
                flag=0;
                break;
            }
            char ch=pop();
            if(ch=='(' &&  (exp[i]=='}' || exp[i]==']' )){
                flag=0;
                break;
            }
            else if(ch=='[' &&  (exp[i]==')' || exp[i]=='}' )){
                flag=0;
                break;
            }
            else if(ch=='{' &&  (exp[i]==')' || exp[i]==']')){
                flag=0;
                break;
            }
        }
        i++;
    }
    if(top!=-1){
        flag=0;
    }
    if(flag==1){
        printf("Valid\n");
    }
    else{
        printf("Invalid\n");
    }
    return 0;
}