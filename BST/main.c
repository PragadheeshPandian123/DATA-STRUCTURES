# include <stdio.h>
# include <stdlib.h>
# include "function.c"

int main() {
    Node* root = NULL;
    int choice, value, parent;
    char side;

    while (1) {
        printf("\n--- Binary Tree Menu (Linked List) ---\n");
        printf("1. Insert Root\n");
        printf("2. Insert Child\n");
        printf("3. Delete Node\n");
        printf("4. Inorder Traversal\n");
        printf("5. Preorder Traversal\n");
        printf("6. Postorder Traversal\n");
        printf("7. Display Tree with X\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if (!root) {
                    printf("Enter root value: ");
                    scanf("%d", &value);
                    root=create_Root(value);
                    printf("Root %d inserted.\n", root->data);
                } else {
                    printf("Root already exists!\n");
                }
                break;
            case 2:
                if (!root) {
                    printf("Tree is empty! Insert root first.\n");
                    break;
                }
                printf("Enter value to be inserted: ");
                scanf("%d",&value);
                root=insert(root,value);
                break;
            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                root=delete(root, value);
                break;
            case 4:
                printf("Inorder: ");
                inorder(root);
                printf("\n");
                break;
            case 5:
                printf("Preorder: ");
                preorder(root);
                printf("\n");
                break;
            case 6:
                printf("Postorder: ");
                postorder(root);
                printf("\n");
                break;
            case 7:
                displayTree(root);
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}