#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) ;
int partitionFirst(int arr[], int low, int high);
int partitionLast(int arr[], int low, int high);
int partitionRandom(int arr[], int low, int high);
void quickSort(int arr[], int low, int high, int mode);

int main()
{
    int *arr,n,choice;
	do{
		printf("\nMenu:\n");
        printf("1. Quick Sort using First element as pivot\n");
        printf("2. Quick Sort using Last element as pivot\n");
        printf("3. Quick Sort using Random element as pivot\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
		
		printf("\n");
		if(choice >= 1 && choice <= 3) {
			printf("Enter the size of array: ");
			scanf("%d",&n);
			arr=(int *)malloc(sizeof(int)*n);
			printf("Enter the elements of the array: \n");
			for(int i=0;i<n;i++)
			{
				printf("Enter arr[%d]: ",i);
				scanf("%d",arr+i);
			}
			printf("The array before sorting is : \n");
			for(int i=0;i<n;i++)
			{
				printf("%d ",*(arr+i));
			}
			printf("\n");
            quickSort(arr, 0, n - 1, choice);
            printf("The array after sorting is : \n");
			for(int i=0;i<n;i++)
			{
				printf("%d ",*(arr+i));
			}
			printf("\n");
        } else if(choice != 4) {
            printf("Invalid choice. Try again.\n");
        }
	}while(choice!=4);
    return 0;
}
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partitionFirst(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low + 1;
    int j = high;

    while (i <= j) {
        while (i <= high && arr[i] <= pivot)
            i++;
        while (j >= low && arr[j] > pivot)
            j--;
        if (i < j)
            swap(&arr[i], &arr[j]);
    }
    swap(&arr[low], &arr[j]); 
    return j; 
}

int partitionLast(int arr[], int low, int high) {
    int pivot = arr[high]; 
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]); 
    return i + 1;
}


int partitionRandom(int arr[], int low, int high) {
    int randomIndex = low + rand() % (high - low + 1);  
    swap(&arr[randomIndex], &arr[high]);  
    return partitionLast(arr, low, high);
}

void quickSort(int arr[], int low, int high, int mode) {
    if(low < high) {
        int pi;
        if(mode == 1)
            pi = partitionFirst(arr, low, high);
        else if(mode == 2)
            pi = partitionLast(arr, low, high);
        else
            pi = partitionRandom(arr, low, high);
        
        quickSort(arr, low, pi - 1, mode);
        quickSort(arr, pi + 1, high, mode);
    }
}

