# include <stdio.h>
# define MAX 10

int st[MAX],top=-1;
void push(int val);
int pop();
int main(){ 
    int n;
    printf("Enter n: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter array: \n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("The array is: \n");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    for(int i=0;i<n;i++){
        push(arr[i]);
    }
    for(int i=0;i<n;i++){
        arr[i]=pop();
    }
    printf("The Reversed array is: \n");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}

void push(int val){
    if(top==MAX-1){
        printf("OVERFLOW\n");
        return;
    }
    top++;
    st[top]=val;
}

int pop(){
    if(top==-1){
        printf("UNDERFLOW\n");
        return -1;
    }
    int val=st[top];
    top--;
    return val;
}