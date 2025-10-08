#include <stdio.h>
#include "functions.c"
#define MAX 100

void get_array();
void print_array();
void insert_element();
void delete_element();
void update_element();
void search_element();
void sort_array();
void split_array();
void merge_arrays();
void reverse_array();

int arr[MAX], n;
int main() {
    int choice;

    printf("Enter the size of the array: ");
    scanf("%d", &n);
    if (n > MAX) {
        printf("Size exceeds MAX limit.\n");
        return 0;
    }

    get_array();
    printf("The array is: \n");
    print_array();

    do {
        printf("\nMAIN MENU\n");
        printf("1. INSERTING AN ELEMENT\n");
        printf("2. DELETING AN ELEMENT\n");
        printf("3. UPDATING AN ELEMENT\n");
        printf("4. SEARCHING AN ELEMENT\n");
        printf("5. SORTING THE ARRAY\n");
        printf("6. SPLITTING INTO TWO ARRAYS\n");
        printf("7. MERGING TWO ARRAYS\n");
        printf("8. REVERSING THE ARRAY\n");
	printf("9. DISPLAY THE ARRAY \n");
        printf("10. QUIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insert_element(); break;
            case 2: delete_element(); break;
            case 3: update_element(); break;
            case 4: search_element(); break;
            case 5: sort_array(); break;
            case 6: split_array(); break;
            case 7: merge_arrays(); break;
            case 8: reverse_array(); break;
	    case 9:printf("The array is : \n"); print_array();break;
            case 10: printf("Exiting program.\n"); break;
            default: printf("Invalid choice! Try again.\n");
        }

        if (choice != 9 && choice!=10) {
            printf("Updated array: ");
            print_array();
        }

    } while (choice != 10);

    return 0;
}

