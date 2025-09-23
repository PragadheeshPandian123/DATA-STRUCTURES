# include <stdio.h>
# include <stdlib.h>
void swap(int * a,int * b);
void selection_sort(int arr[],int size);
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
        selection_sort(arr,n);
        printf("The array after sorting is : \n");
        for(int i=0;i<n;i++)
        {
                printf("%d ",arr[i]);
        }
        printf("\n");
        return 0;
}
void swap(int * a,int * b)
{
        *a=*a+*b;
        *b=*a-*b;
        *a=*a-*b;
}
void selection_sort(int arr[],int size)
{
	int min,i,j;
	for(i=0;i<size-1;i++)
	{
		min=i;
		for(j=i+1;j<size;j++)
		{
			if(arr[min]>arr[j])
			{
				min=j;
			}
		}
		
		if(min!=i)
			swap((arr+i),(arr+min));
	}
}