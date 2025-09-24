# include <stdio.h>
# include <stdlib.h>
# include "functions.c"

int main() {
    int choice, value, parent;
    char side;

    initTree();

    while (1) {
        printf("\n--- Binary Tree Menu ---\n");
        printf("1. Insert Root\n");
        printf("2. Insert Child\n");
        printf("3. Delete Node\n");
        printf("4. Inorder Traversal\n");
        printf("5. Preorder Traversal\n");
        printf("6. Postorder Traversal\n");
        printf("7. Display Tree\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter root value: ");
                scanf("%d", &value);
                insertRoot(value);
                break;
            case 2:
                printf("Enter parent value: ");
                scanf("%d", &parent);
                printf("Enter child value: ");
                scanf("%d", &value);
                printf("Enter side (L/R): ");
                scanf(" %c", &side);
                insertChild(parent, value, side);
                break;
            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteNode(value);
                break;
            case 4:
                printf("Inorder Traversal: ");
                inorder(0);
                printf("\n");
                break;
            case 5:
                printf("Preorder Traversal: ");
                preorder(0);
                printf("\n");
                break;
            case 6:
                printf("Postorder Traversal: ");
                postorder(0);
                printf("\n");
                break;
            case 7:
                display();
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
