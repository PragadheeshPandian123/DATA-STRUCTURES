# include <stdio.h>
# include <stdlib.h>
void counting_sort(int arr[],int size);
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
        counting_sort(arr,n);
        printf("The array after sorting is : \n");
        for(int i=0;i<n;i++)
        {
                printf("%d ",arr[i]);
        }
        printf("\n");
        return 0;
}
void counting_sort(int arr[],int size)
{
	int output[size];
	int digit;
	int count[10]={0};
	for(int i=0;i<size;i++)
	{
		count[arr[i]]++;
	}
	for(int i=1;i<10;i++)
	{
		count[i]=count[i-1]+count[i];
	}
	for(int i=0;i<size;i++)
	{
		digit=arr[i];
		output[count[digit]-1]=arr[i];
		count[digit]--;
	}
	for(int k=size;k>=0;k--)
	{
		arr[k]=output[k];
	}
}
