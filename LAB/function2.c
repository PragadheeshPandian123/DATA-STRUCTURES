#include <stdio.h>
int lin_search(int arr[],int size,int key)
{
	int flag=0;
	for(int i=0;i<size;i++)
	{
		if(arr[i]==key)
		{
			flag=1;
			return i+1;
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


				
