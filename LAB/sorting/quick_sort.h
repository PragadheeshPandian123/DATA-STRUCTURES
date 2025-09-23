# include <stdio.h>
int partition(int a[],int beg,int end)
{
	int left,right,flag,temp,loc;
	loc=left=beg;
	right=end;
	flag=0;
	while(flag!=1)
	{
		while((a[loc]<=a[right]) && (loc!=right))
		{
			right--;
		}	
		if(loc==right)
			flag=1;
		else if(a[loc]>a[right])
		{
			temp=a[loc];
			a[loc]=a[right];
			a[right]=temp;
			loc=right;
		}
		if(flag!=1)
		{
			while((a[loc] >= a[left]) && (loc != left))
				left++;
			if(loc==left)
				flag=1;
			else if (a[loc] < a[left])
			{
				temp=a[loc];
				a[loc]=a[left];
				a[left]=temp;
				loc=left;
			}
		}
	}
	return loc;
}
void quick_sort(int arr[],int beg,int end)
{
	int loc;
	if(beg<end)
	{
		loc=partition(arr,beg,end);
		quick_sort(arr,beg,loc-1);
		quick_sort(arr,loc+1,end);
	}
}
