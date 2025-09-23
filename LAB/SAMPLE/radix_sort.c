# include <stdio.h>
# include <stdlib.h>
void counting_sort(int arr[],int size,int exp);
void radix_sort(int arr[],int size);
int main()
{
        int n;
        printf("Enter the size of the array : ");
        scanf("%d",&n);
        int * arr=(int *)malloc(sizeof(int)*n);
        for(int i=0;i<n;i++)
        {
                printf("Enter arr[%d]: " ,i);
                scanf("%d",&arr[i]);
        }
        printf("The array before sorting is : \n");
        for(int i=0;i<n;i++)
        {
                printf("%d ",arr[i]);
        }
        printf("\n");
        radix_sort(arr,n);
        printf("The array after sorting is : \n");
        for(int i=0;i<n;i++)
        {
                printf("%d ",arr[i]);
        }
        printf("\n");
        return 0;
}
void counting_sort(int arr[],int size,int exp)
{
        int output[size];
        int digit;
        int count[10]={0};
        for(int i=0;i<size;i++)
        {
                count[(arr[i]/exp)%10]++;
        }
        for(int i=1;i<10;i++)
        {
                count[i]=count[i-1]+count[i];
        }
        for(int i=size-1;i>=0;i--)
        {
                digit=(arr[i]/exp)%10;
                output[count[digit]-1]=arr[i];
                count[digit]--;
        }
        for(int k=0;k<size;k++)
        {
                arr[k]=output[k];
        }
}
void radix_sort(int arr[],int size)
{
	int max=arr[0];
	for(int i=1;i<size;i++)
	{
		if(arr[i]>max)
			max=arr[i];
	}
	for(int exp=1;max/exp>0;exp*=10)
	{
		counting_sort(arr,size,exp);
	}
}

