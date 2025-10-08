# include <stdio.h>
void print_alternatives(int arr[],int size)
{
    for(int i=0;i<size;i+=2)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}