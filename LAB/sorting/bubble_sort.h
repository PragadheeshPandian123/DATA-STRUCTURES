# include <stdio.h>
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

