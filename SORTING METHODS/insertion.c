#include <stdio.h>
void print_array(int a[],int size)
{
    for(int i=0;i<size;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}
void insertion_sort(int a[],int size)
{
    int i,j,key;
    for(i=1;i<size;i++)
    {
        int key=a[i];
        int j=i-1;
        while(j>=0 && a[j]>key)
        {
            a[j+1]=a[j];
            j=j-1;
        }
        a[j+1]=key;
        print_array(a,size);
    }
}
int main()
{
    int arr[]={5,2,9,1,5,6};
    print_array(arr,6);
    insertion_sort(arr,6);
    return 0;
}  