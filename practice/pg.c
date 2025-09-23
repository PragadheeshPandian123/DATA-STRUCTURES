# include <stdio.h>

void selection_Sort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    printf("THe array is : \n");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}

int main(){
    int arr[50],n;
    printf("Enter n : ");
    scanf("%d",&n);
    printf("Enter array: \n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    selection_Sort(arr,n);
    return 0;
}