# include <stdio.h>
# define MAX 100
extern int arr[MAX],n;
void get_array() {
    printf("Enter the elements of the array: \n");
    for (int i = 0; i < n; i++) {
        printf("Enter arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }
}

void print_array() {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insert_element() {
    int pos, val,choice;
    if (n == MAX) {
        printf("Array is full. Cannot insert.\n");
        return;
    }
    printf("MENU: \n");
    printf("1.BEGINNING\n");
    printf("2.MIDDLE\n");
    printf("3.END\n");
    printf("Enter your choice : \n");
    scanf("%d",&choice);
    if(choice==1)
    	pos=0;
    else if(choice==3)
	    pos=n;
    else if(choice==2){
	printf("Enter position to insert (0 to %d): ", n);
	 scanf("%d", &pos);
    	if (pos < 0 || pos > n) {
        	printf("Invalid position!\n");
        	return;
   	 }
    }
    else{
	    printf("Invalid choice.\n");
	    return;
    }
    printf("Enter value to insert: ");
    scanf("%d", &val);
    for (int i = n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = val;
    n++;
    printf("Element inserted.\n");
}

void delete_element() {
    int pos,choice;
    if (n == 0) {
        printf("Array is empty. Cannot delete.\n");
        return;
    }
    printf("MENU: \n");
    printf("1.BEGINNING\n");
    printf("2.MIDDLE\n");
    printf("3.END\n");
    printf("Enter your choice : \n");
    scanf("%d",&choice);
    if(choice==1)
        pos=0;
    else if(choice==3)
        pos=n-1;
    else if (choice=2){
        printf("Enter position to delete (0 to %d): ", n);
         scanf("%d", &pos);
        if (pos < 0 || pos > n) {
                printf("Invalid position!\n");
                return;
         }
    }
    else{
	    printf("Ivalid choice\n");
	    return;
    }
    for (int i = pos; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--;
    printf("Element deleted.\n");
}

void update_element() {
    int pos, val;
    printf("Enter position to update (0 to %d): ", n - 1);
    scanf("%d", &pos);
    if (pos < 0 || pos >= n) {
        printf("Invalid position!\n");
        return;
    }
    printf("Enter new value: ");
    scanf("%d", &val);
    arr[pos] = val;
    printf("Element updated.\n");
}

void search_element() {
    int val, found = 0;
    printf("Enter value to search: ");
    scanf("%d", &val);
    for (int i = 0; i < n; i++) {
        if (arr[i] == val) {
            printf("Element found at position %d\n", i);
            found = 1;
            break;
        }
    }
    if (!found)
        printf("Element not found.\n");
}

void sort_array() {
    int choice;
    printf("MENU:\n");
    printf("1.ASCENDING\n");
    printf("2.DESCENDING\n");
    printf("Enter your choice: \n");
    scanf("%d",&choice);
    if(choice!=1 && choice!=2){
	    printf("Invalid Choice\n");
	    return;
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (((choice==1) && (arr[j] > arr[j + 1]))||((choice==2)&&(arr[j]<arr[j+1]))) {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
    printf("Array has been sorted.\n");
}

void split_array() {
    int mid = n / 2;
    printf("First half: ");
    for (int i = 0; i < mid; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nSecond half: ");
    for (int i = mid; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void merge_arrays() {
    int arr2[MAX], m;
    printf("Enter the number of elements in second array: ");
    scanf("%d", &m);
    if (n + m > MAX) {
        printf("Cannot merge, total exceeds max size.\n");
        return;
    }
    printf("Enter elements of second array:\n");
    for (int i = 0; i < m; i++) {
        printf("Enter arr2[%d]: ", i);
        scanf("%d", &arr2[i]);
    }
    for (int i = 0; i < m; i++) {
        arr[n + i] = arr2[i];
    }
    n += m;
    printf("Arrays merged.\n");
}

void reverse_array() {
    int start = 0, end = n - 1;
    while (start < end) {
        int tmp = arr[start];
        arr[start] = arr[end];
        arr[end] = tmp;
        start++;
        end--;
    }
    printf("Array reversed.\n");
}


