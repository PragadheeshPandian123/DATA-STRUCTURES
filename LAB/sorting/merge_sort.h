# include <stdio.h>
#define size 100
void merge(int arr[],int beg,int mid,int end)
{
	int temp[size];
	int i=beg,j=mid+1,index=beg;
	while((i<=mid) && (j<=end))
	{
		if(arr[i] < arr[j])
		{
			temp[index]=arr[i];
			i++;
		}
		else
		{
			temp[index]=arr[j];
			j++;
		}
		index++;
	}
	if(i>mid)
	{
		while(j<=end)
		{
			temp[index]=arr[j];
			j++;
			index++;
		}
	}
	else
	{
		while(i<=mid)
		{
			temp[index]=arr[i];
			i++;
			index++;
		}
	}
	for(int k=beg;k<index;k++)
	{
		arr[k]=temp[k];
	}

}
void merge_sort(int arr[],int lb , int ub)
{
	int mid;
	if(lb<ub)
	{
		mid=(lb+ub)/2;
		merge_sort(arr,lb,mid);
		merge_sort(arr,mid+1,ub);
		merge(arr,lb,mid,ub);
	}
}
