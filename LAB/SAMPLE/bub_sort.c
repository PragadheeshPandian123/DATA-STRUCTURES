# include <stdio.h>
# include <stdlib.h>
void swap(int *a,int*b);
void bub_sort(int arr[],int size);

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
        bub_sort(arr,n);
        printf("The array after sorting is : \n");
        for(int i=0;i<n;i++)
        {
                printf("%d ",arr[i]);
        }
        printf("\n");
        return 0;
}

void swap(int *a,int*b)
{
	*a=*a+*b;
	*b=*a-*b;
	*a=*a-*b;
}
void bub_sort(int arr[],int size)
{
	int flag=0,i,j;
	for(i=0;i<size-1;i++)
	{
		flag=0;
		for(j=0;j<size-i-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				flag=1;
				swap(&arr[j],&arr[j+1]);
			}
		}
		if(flag==0)
			break;
	}
}

