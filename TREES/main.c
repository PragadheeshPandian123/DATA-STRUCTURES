#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void insertRoot(Node** root, int value) {
    if (*root == NULL) {
        *root = createNode(value);
        printf("Root %d inserted\n", value);
    } else {
        printf("Root already exists!\n");
    }
}

Node* search(Node* root, int value) {
    if (root == NULL) return NULL;
    if (root->data == value) return root;

    Node* left = search(root->left, value);
    if (left != NULL) return left;
    return search(root->right, value);
}


void insertChild(Node* root, int parent, int value, char side) {
    Node* parentNode = search(root, parent);
    if (parentNode == NULL) {
        printf("Parent %d not found!\n", parent);
        return;
    }

    if (side == 'L' || side == 'l') {
        if (parentNode->left != NULL) {
            printf("Left child already exists for %d\n", parent);
        } else {
            parentNode->left = createNode(value);
            printf("Inserted %d as left child of %d\n", value, parent);
        }
    } else if (side == 'R' || side == 'r') {
        if (parentNode->right != NULL) {
            printf("Right child already exists for %d\n", parent);
        } else {
            parentNode->right = createNode(value);
            printf("Inserted %d as right child of %d\n", value, parent);
        }
    } else {
        printf("Invalid side! Use 'L' or 'R'.\n");
    }
}

Node* getDeepestRightmost(Node* root, Node** parent) {
    if (root == NULL) return NULL;

    Node* queue[100];
    int front = 0, rear = 0;

    queue[rear++] = root;
    Node* current = NULL;

    while (front < rear) {
        current = queue[front++];
        if (current->left) {
            *parent = current;
            queue[rear++] = current->left;
        }
        if (current->right) {
            *parent = current;
            queue[rear++] = current->right;
        }
    }

    return current;
}

void deleteNode(Node** root, int value) {
    if (*root == NULL) {
        printf("Tree is empty!\n");
        return;
    }

    if ((*root)->left == NULL && (*root)->right == NULL) {
        if ((*root)->data == value) {
            free(*root);
            *root = NULL;
            printf("Deleted %d successfully\n", value);
        } else {
            printf("Value not found!\n");
        }
        return;
    }

    Node* target = NULL;
    Node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = *root;

    while (front < rear) {
        Node* temp = queue[front++];
        if (temp->data == value)
            target = temp;
        if (temp->left)
            queue[rear++] = temp->left;
        if (temp->right)
            queue[rear++] = temp->right;
    }

    if (target == NULL) {
        printf("Value not found!\n");
        return;
    }

    Node* parent = NULL;
    Node* deepest = getDeepestRightmost(*root, &parent);

    if (deepest == NULL) return;

    target->data = deepest->data;

    if (parent->right == deepest)
        parent->right = NULL;
    else
        parent->left = NULL;

    free(deepest);

    printf("Deleted %d successfully\n", value);
}

void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

void display(Node * root,int space)
{
    if(root==NULL){
        return;
    }
    space=space+5;
    display(root->right,space);
    for(int i=5;i<space;i++){
        printf(" ");
    }
    printf("%d\n",root->data);
    display(root->left,space);
}

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
        printf("7. Display Tree (Level Order)\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter root value: ");
                scanf("%d", &value);
                insertRoot(&root, value);
                break;
            case 2:
                printf("Enter Parent value: ");
                scanf("%d", &parent);
                printf("Enter child value: ");
                scanf("%d", &value);
                printf("Enter side (L/R): ");
                scanf(" %c", &side);
                insertChild(root, parent, value, side);
                break;
            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteNode(&root, value);
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
                display(root,0);
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
