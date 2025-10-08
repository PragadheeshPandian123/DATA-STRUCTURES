# include <stdio.h>
# include <stdlib.h>

# include "functions.c"

int main(){
    int n,cont,*arr,*hashTable,m,choice1,choice2,temp,c1,c2,m2,*hashTableSize;
    Node **chain;
    int key,k;

    do{
        printf("Enter array size: ");
        scanf("%d",&n);
        arr=(int*)malloc(n*sizeof(int));
        get_array(arr,n);
        printf("The Array is: \n");
        print_array(arr,n);

        printf("Enter the size of hashTable: ");
        scanf("%d",&m);
        hashTable=create_hashTable(hashTable,m);

        printf("HASH FUNCTION MENU\n");
        printf("1. Division Method\n");
        printf("2. Multiplication Method\n");

        printf("Enter choice: ");
        scanf("%d",&choice1);

        printf("COLLISION RESOLVING\n");
        printf("1. Open Addressing\n");
        printf("2. Chaining\n");
        printf("Enter your choice: ");
        scanf("%d",&temp);

        if(temp==1)   
        {
            printf("COLLISION RESOLVING MENU\n");
            printf("1. Linear Probing\n");
            printf("2. Quadratic Probing\n");
            printf("3. Double Hashing\n");
            printf("4. Rehashing\n");

            printf("Enter choice: ");
            scanf("%d",&choice2);

            if(choice2==1)
            {
                hashTable= LinearProbingInsert(hashTable,arr,n,m,choice1);
            }
            else if(choice2==2)
            {
                printf("Enter c1 and c2 for Quadratic Probing: \n");
                scanf("%d %d",&c1,&c2);
                hashTable= QuadraticProbingInsert(hashTable,arr,n,m,choice1,c1,c2);
            }
            else if(choice2==3)
            {
                printf("Enter the m2 value for second hash function: ");
                scanf("%d",&m2);
                hashTable= DoubleHashingInsert(hashTable,arr,n,m,m2,choice1);
            }
            else if(choice2==4)
            {
                hashTableSize=&m;
                hashTable= RehashingInsert(hashTable,arr,n,hashTableSize,choice1);
            }

            printf("The hash table is : \n");
            displayhashTable(hashTable,m);

            free(hashTable);   
        }
        else if(temp==2)   
        {
            chain=(Node **)malloc(m*sizeof(Node *));
            initChain(chain,m);

            for(int i=0;i<n;i++)
            {
                key=arr[i];
                k= (choice1 == 1) ? hashDiv(key,m) : hashMultiply(key,m);
                chainingInsert(chain,key,k);
            }

            printf("The hash table is: \n");
            displayChaining(chain,m);

            freeChain(chain, m);  
        }

        free(arr); 

        printf("Do you want to continue ( 1 or 0 ): ");
        scanf("%d",&cont);

    }while(cont==1);

    return 0;
}
