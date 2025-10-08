# include <stdio.h>
# define MAX 100

int arr[MAX],n=5;

void get_array(){
    printf("Enter the array: \n");
    for(int i=0;i<n;i++){
        printf("Enter arr[%d]: ",i);
        scanf("%d",&arr[i]);
    }
}

void print_array()
{
    printf("The array is : \n");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}

void insert_element(){
    int val,index;
    printf("Enter the value: ");
    scanf("%d",&val);

    printf("Enter index : ");
    scanf("%d",&index);

    for(int i=n+1;i>index;i--){
        arr[i]=arr[i-1];
    }
    arr[index]=val;
    printf("Array Updated \n");
}

void delete_element(){
    int index;
    printf("Enter the index to be deleted: ");
    scanf("%d",&index);

    for(int i=index;i<n-1;i++){
        arr[i]=arr[i+1];
    }
    n=n-1;
    printf("Element deleted \n");
}

void Linear_search(){
    int val;
    printf("Enter the value to be searched : ");
    scanf("%d",&val);
    int pos=-1;
    for(int i=0;i<n;i++){
        if(arr[i]==val){
            pos=i;
            break;
        }
    }
    if(pos){
        printf("The element found at %d : ",pos);
    }
    else{
        printf("Element not found \n");
    }
}

void sort(){
    int flag=0;
    for(int i=0;i<n-1;i++){
        flag=0;
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                flag=1;
                int temp=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=temp;
            }
        }
        if(flag){
            break;
        }
    }
}


void Binary_search(){
    int val;
    printf("Enter the value to be searched : ");
    scanf("%d",&val);
    printf("Sorting Before Applying Binary Search \n");
    sort();
    int flag=0;
    int high=n-1,low=0,mid;
    while(low<=high){
        mid=(low + high)/2;
        if(arr[mid]<val){
            low=mid+1;
        }
        else if(arr[mid]>val){
            high=mid-1;
        }
        else{
            flag=1;
            printf("The element found at : %d",mid);
            break;
        }
    }
    if(flag){
        printf("Element not found \n");
    }
}

void search_element(){
    int choice;
    printf("Enter choice ( 1: Linear Search 2: Binary Search) \n: ");
    scanf("%d",&choice);

    (choice==1)? Linear_search():Binary_search();
}

void reverse_array(){
    for(int i=0;i<n/2;i++){
        arr[i]=arr[n-i-1];
    }
    printf("The Array reversed \n");
}

int main(){
    get_array();
    print_array();
    insert_element();
    print_array();
    delete_element();
    print_array();
    search_element();
    search_element();
    reverse_array();
    print_array();
    return 0;
}