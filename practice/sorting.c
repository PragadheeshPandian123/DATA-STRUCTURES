# include <stdio.h>

void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void bubble_sort(int arr[],int n){
    int flag=0;
    for(int i=0;i<n-1;i++){
        flag=0;
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                flag=1;
                swap(&arr[j],&arr[j+1]);
            }
        }
        if(flag==0){
            break;
        }
    }
}

void insertion_sort(int arr[],int n){
    int i,j,key;
    for(i=1;i<n;i++){
        key=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key;
    }
}

void counting_Sort(int arr[],int n,int exp){
    int output[n],count[10]={0},index=0,digit;
    for(int i=0;i<n;i++){
        count[(arr[i]/exp)%10]++;
    }
    for(int i=1;i<10;i++){
        count[i]=count[i-1]+count[i];
    }
    for(int j=n-1;j>=0;j--){
        digit=(arr[j]/exp)%10;
        output[count[digit]-1]=arr[j];
        count[digit]--;
    }
    for(int j=0;j<n;j++){
        arr[index++]=output[j];
    }
}

void radix_sort(int arr[],int n){
    int max=arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    for(int exp=1;max/exp>0;exp*=10){
        counting_Sort(arr,n,exp);
    }
}

void selection_Sort(int arr[],int n){
    int min=0;
    for(int i=0;i<n-1;i++){
        min=i;
        for(int j=i+1;j<n;j++){
            if(arr[min]>arr[j]){
                min=j;
            }
        }
        swap(&arr[i],&arr[min]);
    }
}


void merge(int arr[],int beg,int mid,int end){
    int i=beg,j=mid+1;
    int temp[end-1],index=beg;
    while(i<=mid && j<=end){
        if(arr[i]<arr[j]){
            temp[index++]=arr[i];
            i++;
        }
        else{
            temp[index++]=arr[j];
            j++;
        }
    }
    if(i>mid){
        while(j<=end){
            temp[index++]=arr[j++];
        }
    }
    if(j>end){
        while(i<=mid){
            temp[index++]=arr[i++];
        }
    }
    for(int i=beg;i<index;i++){
        arr[i]=temp[i];
    }
}

void mergeSort(int arr[],int beg,int end){
    int mid;
    if(beg<end){
        mid=(beg+end)/2;
        mergeSort(arr,beg,mid);
        mergeSort(arr,mid+1,end);
        merge(arr,beg,mid,end);
    }
}
int partition(int arr[],int beg,int end){
    int pivot=arr[end];//end pivot
    int i=beg-1;
    for(int j=beg;j<end;j++){
        if(arr[j]<pivot){
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(arr[i+1],arr[end]);
}

int partitionfirst(int arr[],int beg,int end){
    int pivot=arr[beg];
    int i=beg+1,j=end;
    while(i<=j){
    while(i<=end && arr[i]<=pivot){
        i++;
    }
    while(j>=beg && arr[j]>pivot){
        j--;
    }
    if(i<j){
        swap(&arr[i],&arr[j]);
    }
}
    swap(&arr[beg],&arr[j]);
}

void quicksort(int arr[],int beg,int end){
    if(beg<end){
        int pi=partition(arr,beg,end);
        quicksort(arr,beg,pi-1);
        quicksort(arr,pi+1,end);
    }
}

int main(){
    int arr[5]={5,4,3,2,1};
    mergeSort(arr,0,4);
    printf("The array : \n");
    for(int i=0;i<5;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}