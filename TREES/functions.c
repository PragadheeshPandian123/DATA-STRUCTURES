#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int tree[MAX];

void initTree() {
    for (int i = 0; i < MAX; i++) {
        tree[i] = -1;
    }
}

void insertRoot(int value) {
    if (tree[0] == -1) {
        tree[0] = value;
        printf("Root %d inserted\n", value);
    } else {
        printf("Root already exists!\n");
    }
}

void insertChild(int parent, int value, char side) {
    for (int i = 0; i < MAX; i++) {
        if (tree[i] == parent) {
            int childIndex = (side == 'L' || side == 'l') ? 2 * i + 1 : 2 * i + 2;
            if (childIndex >= MAX) {
                printf("Out of bounds\n");
                return;
            }
            if (tree[childIndex] != -1) {
                printf("Child already exists at %c of %d\n", side, parent);
                return;
            }
            tree[childIndex] = value;
            printf("Inserted %d as %c child of %d\n", value, side, parent);
            return;
        }
    }
    printf("Parent %d not found!\n", parent);
}

int getDeepestRightmost() {
    int last = -1;
    for (int i = 0; i < MAX; i++) {
        if (tree[i] != -1) {
            last = i;
        }
    }
    return last;
}

void deleteNode(int value) {
    int targetIndex = -1;
    for (int i = 0; i < MAX; i++) {
        if (tree[i] == value) {
            targetIndex = i;
            break;
        }
    }
    if (targetIndex == -1) {
        printf("Value not found\n");
        return;
    }

    int deepestIndex = getDeepestRightmost();
    if (deepestIndex == targetIndex) {
        tree[targetIndex] = -1;
    } else {
        tree[targetIndex] = tree[deepestIndex];
        tree[deepestIndex] = -1;
    }
    printf("Deleted %d successfully\n", value);
}

void inorder(int index) {
    if (index >= MAX || tree[index] == -1) return;
    inorder(2 * index + 1);
    printf("%d ", tree[index]);
    inorder(2 * index + 2);
}

void preorder(int index) {
    if (index >= MAX || tree[index] == -1) return;
    printf("%d ", tree[index]);
    preorder(2 * index + 1);
    preorder(2 * index + 2);
}

void postorder(int index) {
    if (index >= MAX || tree[index] == -1) return;
    postorder(2 * index + 1);
    postorder(2 * index + 2);
    printf("%d ", tree[index]);
}

void display() {
    if (tree[0] == -1) {
        printf("Tree is Empty\n");
        return;
    }
    int queue[2 * MAX];
    int front = 0, rear = 0;
    queue[rear++] = 0;

    while (front < rear) {
        int nodeCount = rear - front;
        int allNullInLevel = 1;
        for (int i = front; i < rear; i++) {
            int idx = queue[i];
            if (idx != -1 && tree[idx] != -1) {
                allNullInLevel = 0;
                break;
            }
        }
        if (allNullInLevel) break;

        for (int i = 0; i < nodeCount; i++) {
            int idx = queue[front++];
            if (idx != -1 && idx < MAX && tree[idx] != -1) {
                printf(" %d ", tree[idx]);
                int left = 2 * idx + 1;
                int right = 2 * idx + 2;
                queue[rear++] = (left < MAX) ? left : -1;
                queue[rear++] = (right < MAX) ? right : -1;
            } else {
                printf(" X ");
                queue[rear++] = -1;
                queue[rear++] = -1;
            }
        }
        printf("\n");
    }
}

int main() {
    int choice, value, parent;
    char side;
    initTree();

    while (1) {
        printf("\n--- Binary Tree Menu (Array) ---\n");
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

        switch (choice) {
            case 1:
                printf("Enter root value: ");
                scanf("%d", &value);
                insertRoot(value);
                break;
            case 2:
                printf("Enter Parent value: ");
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
                printf("Inorder: ");
                inorder(0);
                printf("\n");
                break;
            case 5:
                printf("Preorder: ");
                preorder(0);
                printf("\n");
                break;
            case 6:
                printf("Postorder: ");
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
