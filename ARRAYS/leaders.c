# include <stdio.h>
# include <stdlib.h>
int * leader_array(int arr[],int size)
{
    int * output=(int * )malloc(size * sizeof(int));
    int flag=0;
    int leader,k,i;
    for(i =0;i<size-1;i++)
    {
        leader=arr[i];
        for(int j=i+1;j<size;j++)
        {
            if(leader<arr[j])
                flag=1;
        }
        if(flag==0)
            output[k++]=leader;
    }
    output[k]=arr[i+1];
    return output;
}