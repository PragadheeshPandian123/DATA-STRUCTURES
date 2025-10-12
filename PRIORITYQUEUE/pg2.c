# include <stdio.h>
# include <stdlib.h>
# define MAX 100 

int PQ[MAX],size=0;
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void heapifyUp(int index){
    if(index && PQ[(index-1)/2]> PQ[index]){
        swap(&PQ[(index-1)/2],&PQ[index]);
        heapifyUp((index-1)/2);
    }
}

void heapifyDown(int index){
    int smallest=index;
    int left=2*index+1;
    int right=2*index + 2;

    if(index<size && PQ[smallest]>PQ[left]){
        smallest=left;
    }
    else if(index < size && PQ[smallest]>PQ[right]){
        smallest=right;
    }
    if(smallest!=index){
        swap(&PQ[index],&PQ[smallest]);
    }
}

void insertPQ(int val){
    if(size==MAX-1){
        printf("OVERFLOW \n");
        return;
    }
    else{
        PQ[size++]=val;
        heapifyUp(size-1);
        printf("Successfully inserted. \n");
    }
}

void deletePQ(){
    if(size==-1){
        printf("UNDERFLOW\n");
        return;
    }
    else{
        int item=PQ[0];
        PQ[0]=PQ[--size];
        heapifyDown(0);
        printf("The deleted element is : %d\n",item);
    }
}


void heapSort() {
    if (size == 0) {
        printf("Priority Queue is Empty\n");
        return;
    }

    int tempPQ[MAX];
    int tempSize = size;

    for (int i = 0; i < size; i++)
        tempPQ[i] = PQ[i];

    printf("Sorted elements (Heap Sort): ");
    
    while (tempSize > 0) {

        printf("%d ", tempPQ[0]);

        tempPQ[0] = tempPQ[--tempSize];

        int index = 0;
        while (1) {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int smallest = index;

            if (left < tempSize && tempPQ[left] < tempPQ[smallest])
                smallest = left;
            if (right < tempSize && tempPQ[right] < tempPQ[smallest])
                smallest = right;

            if (smallest != index) {
                int temp = tempPQ[index];
                tempPQ[index] = tempPQ[smallest];
                tempPQ[smallest] = temp;
                index = smallest;
            } else {
                break;
            }
        }
    }
    printf("\n");
}


int main()
{
    int choice,value;
    do
    {
        printf("========= Priority Queue(Using Binary heap) Menu ========= \n");
        printf(" 1. Insert \n 2. Delete \n 3. Display(Heap sort) \n");
        printf("Enter chocie : ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("Enter Value : ");
            scanf("%d",&value);
            insertPQ(value);
            break;
        case 2:
            deletePQ();
            break;
        case 3:
            printf("Priority Queue : \n");
            heapSort();
            break;
        case 4:
            printf("Exiting...");
            break;
        default:
            printf("Invalid Choice ! Try Again \n");
            break;
        }
    } while (choice!=4);
    
}