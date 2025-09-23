# include <stdio.h>
# include "functions.c"


int main() {
    int choice;
 
    do {
        printf("\n----- LINKED LIST MENU -----\n");
        printf("1. CREATE LINKED LIST\n");
        printf("2. INSERT NODE\n");
        printf("3. DELETE NODE\n");
        printf("4. UPDATING A NODE\n");
        printf("5. SORTING THE LINKED LIST\n");
        printf("6. REVERSE THE LINKED LIST\n");
        printf("7. DELETE THE LINKED LIST\n");
        printf("8. DISPLAY THE LINKED LIST\n");
        printf("9. QUIT\n");   
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: create_list(); break;
            case 2: insert_node(); break;
            case 3: delete_node(); break;
            case 4: update(); break;
            case 5: sort_list(); break;
            case 6: reverse_list(); break;
            case 7: delete_list(); break;
            case 8: display_list(); break;
            case 9: printf("Exiting program.\n"); break;
            default: printf("Invalid choice!\n");
        }

        if (choice != 9 && choice!=8) {
            printf("Current List: ");
            display_list();
        }

    } while (choice != 9);

    return 0;
}