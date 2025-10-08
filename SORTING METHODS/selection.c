# include <stdio.h>
void swap(int * a,int *b)
{
    *a=*a+*b;
    *b=*a-*b;
    *a=*a-*b;
}
void selection_sort(int a[],int size)
{
    int i,j,min;
    for(i=0;i<size-1;i++)
    {
        min=i;
        for(j=i+1;j<size-1;j++)
        {
            if(a[min]>a[j])
            {
                min=j;
            }
        }
        swap(&a[i],&a[min]);
    }
}