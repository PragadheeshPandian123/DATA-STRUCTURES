# include <stdio.h>
# include <stdlib.h>

void insertion_sort(int arr[],int size);
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
        insertion_sort(arr,n);
        printf("The array after sorting is : \n");
        for(int i=0;i<n;i++)
        {
                printf("%d ",arr[i]);
        }
        printf("\n");
        return 0;
}
void insertion_sort(int arr[],int size)
{
	int j,key;
	for(int i=1;i<size;i++)
	{
		key=arr[i];
		j=i-1;
		while(j>=0 && arr[j]>key)
		{
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=key;
	}
}
