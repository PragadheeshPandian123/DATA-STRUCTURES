#include <stdio.h>
void bub_sort(int arr[],int size)
{
	int temp;
	for(int i=0;i<size-1;i++)
	{
		for(int j=0;j<size-i-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
}
int bin_search(int arr[],int size,int key)
{
	int low=0,high=size-1,mid;
	int flag=0;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(arr[mid]==key)
		{
			flag=1;
			return mid+1;
		}
		else if(arr[mid]>key)
		{
			high=mid-1;
		}
		else if(arr[mid]<key)
		{
			low=mid+1;
		}
	}
	if(flag==0)
		return -1;
}
void get_array(int arr[],int size)
{
	for(int i=0;i<size;i++)
        {
                printf("Enter arr[%d]: ",i);
				scanf("%d",&arr[i]);
        }
}
void print_array(int arr[],int size)
{
	for(int i=0;i<size;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}
