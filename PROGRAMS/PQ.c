# include <stdio.h>
# include <stdlib.h>
# define MAX 10

int PQ[MAX],size=0;

void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

int findMin(int PQ[],int a,int b)
{
    if(PQ[a]>PQ[b])return b;
    return a;
}
void heapifyUp(int index)
{
    if(index && PQ[(index-1)/2]>PQ[index])
    {
        swap(&PQ[(index-1)/2],&PQ[index]);
        heapifyUp((index-1)/2);
    }
}

void heapifyDown(int index)
{
    int smallest=index;
    int left=2*index + 1;
    int right=2*index + 2;
    
    if(left < size && right < size){
        int minChildPos=findMin(PQ,left,right);
        smallest=findMin(PQ,smallest,minChildPos);
        if(smallest!=index){
            swap(&PQ[index],&PQ[smallest]);
            heapifyDown(smallest);
        }
    }
}

void insertPQ(int val)
{
    if(size==MAX){
        printf("OVERFLOW\n");
        return;
    }
    else 
    {
        PQ[size++]=val;
        heapifyUp(size-1);
        printf("Successfully inserted \n");
    }
}

int deletePQ()
{
    if(size==0)
    {
        printf("UNDERFLOW\n");
        return -1;
    }
    else
    {
        int item=PQ[0];
        PQ[0]=PQ[--size];
        heapifyDown(0);
        return item;
    }
}

void displayPQ()
{
    if(size==0)
    {
        printf("EMPTY PRIORITY QUEUE \n");
        return;
    }
    else{
        for(int i=0;i<size;i++)
        {
            printf(" %d ",PQ[i]);
        }
        printf("\n");
    }
}

void heapSort()
{
    if(size==0)
    {
        printf("Empty Priority Queue \n");
    }
    int tempPQ[MAX],tempSize=size;
    for(int i=0;i<size;i++)
    {
        tempPQ[i]=PQ[i];
    }
    int sortedArray[MAX],k=0;
    while(tempSize>0)
    {
        sortedArray[k++]=tempPQ[0];
        tempPQ[0]=tempPQ[--tempSize];
        int index=0;
        while(1)
        {
            int smallest=index;
            int left=2*index+1;
            int right=2*index+2;

            if(left < tempSize && right < tempSize)
            {
                int minChildPos=findMin(tempPQ,left,right);
                smallest=findMin(tempPQ,smallest,minChildPos);
                if(smallest!=index)
                {
                    swap(&tempPQ[index],&tempPQ[smallest]);
                    index=smallest; 
                }else break;
            }
        }
    }
    printf("Sorted using Heap Sort : \n ");
    for(int i=0;i<size;i++)
    {
        printf(" %d ",sortedArray[i]);
    }
    printf(" \n");
}

