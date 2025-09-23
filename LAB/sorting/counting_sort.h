# include <stdio.h>
void counting_sort(int arr[],int size)
{
	int output[size];
	int digit;
	int count[10]={0};
	for(int i=0;i<size;i++)
	{
		count[arr[i]]++;
	}
	for(int i=1;i<size;i++)
	{
		count[i]=count[i-1]+count[i];
	}
	for(int i=0;i<size;i++)
	{
		digit=arr[i]%10;
		output[count[digit]-1]=arr[i];
		count[digit]--;
	}
	for(int k=0;k<size;k++)
	{
		arr[k]=output[k];
	}
}
