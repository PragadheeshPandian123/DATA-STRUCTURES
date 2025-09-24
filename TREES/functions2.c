#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert child under parent node
void insertChild(struct Node* root, int parentValue, int childValue, char side) {
    if (!root) return;

    // BFS to find parent
    struct Node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        struct Node* curr = queue[front++];
        if (curr->data == parentValue) {
            if (side == 'L') {
                if (curr->left != NULL) {
                    printf("Left child already exists!\n");
                } else {
                    curr->left = createNode(childValue);
                    printf("Inserted %d as left child of %d\n", childValue, parentValue);
                }
            } else if (side == 'R') {
                if (curr->right != NULL) {
                    printf("Right child already exists!\n");
                } else {
                    curr->right = createNode(childValue);
                    printf("Inserted %d as right child of %d\n", childValue, parentValue);
                }
            }
            return;
        }
        if (curr->left) queue[rear++] = curr->left;
        if (curr->right) queue[rear++] = curr->right;
    }

    printf("Parent %d not found!\n", parentValue);
}

// Find deepest rightmost node and its parent
void findDeepestRightmost(struct Node* root, struct Node** deepest, struct Node** parent) {
    if (!root) return;
    struct Node* queue[100];
    struct Node* parents[100];
    int front = 0, rear = 0;

    queue[rear] = root;
    parents[rear++] = NULL;

    while (front < rear) {
        struct Node* curr = queue[front];
        struct Node* par = parents[front++];
        if (curr->left) {
            queue[rear] = curr->left;
            parents[rear++] = curr;
        }
        if (curr->right) {
            queue[rear] = curr->right;
            parents[rear++] = curr;
        }
        *deepest = curr;
        *parent = par;
    }
}

// Delete node by replacing with deepest rightmost
void deleteNode(struct Node** rootRef, int value) {
    struct Node* root = *rootRef;
    if (!root) {
        printf("Tree is empty!\n");
        return;
    }

    if (root->left == NULL && root->right == NULL) {
        if (root->data == value) {
            free(root);
            *rootRef = NULL;
            printf("Deleted %d\n", value);
        } else {
            printf("Value not found!\n");
        }
        return;
    }

    struct Node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;
    struct Node* nodeToDelete = NULL;

    while (front < rear) {
        struct Node* curr = queue[front++];
        if (curr->data == value) nodeToDelete = curr;
        if (curr->left) queue[rear++] = curr->left;
        if (curr->right) queue[rear++] = curr->right;
    }

    if (!nodeToDelete) {
        printf("Value not found!\n");
        return;
    }

    // Get deepest rightmost node
    struct Node* deepest = NULL;
    struct Node* parent = NULL;
    findDeepestRightmost(root, &deepest, &parent);

    // Replace data
    nodeToDelete->data = deepest->data;

    // Delete deepest node
    if (parent->left == deepest)
        parent->left = NULL;
    else
        parent->right = NULL;

    free(deepest);

    printf("Deleted %d successfully\n", value);
}

// Traversals
void inorder(struct Node* root) {
    if (!root) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(struct Node* root) {
    if (!root) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

// Display with X for NULL nodes (level-order)
void displayWithX(struct Node* root) {
    if (!root) {
        printf("Tree is empty!\n");
        return;
    }

    struct Node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        int nodeCount = rear - front;
        int allNullInLevel = 1;

        // Check if next level has non-NULL nodes
        for (int i = front; i < rear; i++) {
            if (queue[i] != NULL) {
                allNullInLevel = 0;
                break;
            }
        }
        if (allNullInLevel) break;

        for (int i = 0; i < nodeCount; i++) {
            struct Node* curr = queue[front++];
            if (curr) {
                printf("%d ", curr->data);
                queue[rear++] = curr->left;
                queue[rear++] = curr->right;
            } else {
                printf("X ");
                queue[rear++] = NULL;
                queue[rear++] = NULL;
            }
        }
        printf("\n");
    }
}


