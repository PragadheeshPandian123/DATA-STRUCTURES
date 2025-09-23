# include <stdio.h>
int main()
{
    int a[6]={45,75,1,5,78,12};
    int n=6,temp;
    int flag=0;
    for(int i=0;i<n-1;i++)
    {
      flag=0;
        for(int j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                flag=1;
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
        if(flag==0)
            break;
    }
    for(int i=0;i<=n-1;i++)
    {
        printf("%d ",a[i]);
    }
}