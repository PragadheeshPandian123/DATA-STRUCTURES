# include <stdio.h>
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
		//int temp=arr[i];
		//arr[i]=arr[min];
		//arr[min]=temp;
		if(min!=i)
			swap((arr+i),(arr+min));
	}
}
