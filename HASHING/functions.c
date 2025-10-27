# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# define EMPTY -1

typedef struct node 
{
    int data;
    struct node * next;
} Node;

void get_array(int arr[],int n){
    for(int i=0;i<n;i++){
        printf("Enter arr[%d]: ",i);
        scanf("%d",&arr[i]);
    }
}

void print_array(int arr[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int * create_hashTable(int *hashTable,int m){
    hashTable=(int *)malloc(m*sizeof(int));
    for (int i = 0; i < m; i++)
        hashTable[i] = EMPTY;
    return hashTable;
}

int hashDiv(int n,int m){
    return n%m;
}

int hashMultiply(int n,int m){
    const double A= (sqrt(5)-1)/2;
    double temp=(n*A)-floor(n*A);
    int val=(int)(m*temp);
    return val;
}

int *LinearProbingInsert(int *hashTable,int *arr,int arrSize,int m,int choice){
    for(int i=0;i<arrSize;i++)
    {
        int collideCount=0;
        int intpos=(choice==1)?hashDiv(arr[i],m):hashMultiply(arr[i],m);
        int pos=intpos;
        while(1)
        {
            if(hashTable[pos]==EMPTY)
            {
                hashTable[pos]=arr[i];
                break;
            }
            else
            {
                pos=(intpos+(collideCount++))%m;
            }
        }
    }
    return hashTable;
}
    

int* QuadraticProbingInsert(int *hashTable, int *arr, int arrSize, int m, int choice, int c1, int c2)
{
    for (int i = 0; i < arrSize; i++)
    {
        int key = arr[i];
        int base = (choice == 1) ? hashDiv(key, m) : hashMultiply(key, m);

        int pos = base;
        int j = 0;
        int inserted = 0;
        
        while (j < m)
        {
            pos = (base + c1 * j + c2 * j * j) % m;

            if (hashTable[pos] == EMPTY)
            {
                hashTable[pos] = key;
                inserted = 1;
                break;
            }
            j++;
        }

        if (!inserted)
        {
            printf("Could not insert %d using Quadratic Probing (table full or bad parameters)\n", key);
        }
    }
    return hashTable;
}


int* DoubleHashingInsert(int *hashTable, int *arr, int arrSize, int m, int n, int choice)
{
    for (int i = 0; i < arrSize; i++)
    {
        int key = arr[i];
        int h1 = (choice == 1) ? hashDiv(key, m) : hashMultiply(key, m);
        int h2 = n - (key % n);  

        if (h2 == 0) h2 = 1;   
        int pos = h1;
        int j = 0;
        int inserted = 0;
        while (j < m)
        {
            pos = (h1 + j * h2) % m;

            if (hashTable[pos] == EMPTY)
            {
                hashTable[pos] = key;
                inserted = 1;
                break;
            }
            j++;
        }

        if (!inserted)
        {
            printf("Could not insert %d using Double Hashing (table full or bad parameters)\n", key);
        }
    }
    return hashTable;
}

int *RehashingInsert(int *hashTable,int *arr,int arrSize,int *m,int choice)
{
    for(int i=0,k=0;i<arrSize;i++)
    {
        int collideCount=0;
        int intpos=(choice==1)?hashDiv(arr[i],*m):hashMultiply(arr[i],*m);
        int pos=intpos;
        if(*m-k<=1)
        {
            printf("Rehashing needed\n");
            *m=*m*2;
            hashTable=create_hashTable(hashTable,*m);
            i=-1,k=0;
            continue;
        }
        while(1)
        {
            if(hashTable[pos]==EMPTY)
            {
                hashTable[pos]=arr[i];
                k++;
                break;
            }
            else
            {
                pos=(intpos+(collideCount++))%(*m);
            }
        }
    }
    return hashTable;
}

void displayhashTable(int * hashTable,int n)
{
    printf("\nHash Table (Open Addressing): \n");
    for(int i=0;i<n;i++)
    {
        if(hashTable[i]!=EMPTY)
        {
            printf("[%d] ---> %d\n",i,hashTable[i]);
        }
        else
        {
            printf("[%d] ---> EMPTY \n");
        }
    }
}

void initChain(Node * chain[],int m) {
    for (int i = 0; i < m; i++)
        chain[i] = NULL;
}


void chainingInsert(Node *chain[],int key, int index) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = key;
    newNode->next = NULL;

    if(chain[index]==NULL)
    {
        chain[index]=newNode;
    }
    else{
        Node * curr=chain[index];
        while(curr->next!=NULL)
        {
            curr=curr->next;
        }
        curr->next = newNode;
    }
}

void displayChaining(Node * chain[],int m) {
    for (int i = 0; i < m; i++) {
        printf("[%d]", i);
        Node* temp = chain[i];
        while (temp) {
            printf(" --> %d", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

void freeChain(Node **chain, int m) {
    for (int i = 0; i < m; i++) {
        Node *curr = chain[i];
        while (curr != NULL) {
            Node *temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
    free(chain);
}