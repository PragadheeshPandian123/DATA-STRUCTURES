# include <stdio.h>
# include <stdlib.h>
void merge(int arr[],int beg,int mid,int end);
void merge_sort(int arr[],int lb , int ub);
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
        merge_sort(arr,0,n-1);
        printf("The array after sorting is : \n");
        for(int i=0;i<n;i++)
        {
                printf("%d ",arr[i]);
        }
        printf("\n");
        return 0;
}
void merge(int arr[],int beg,int mid,int end)
{
	int temp[end-1];
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
