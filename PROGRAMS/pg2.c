#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int val) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = val;
    n->left = n->right = NULL;
    return n;
}

// Insert node in level order
struct Node* insert(struct Node* root, int val) {
    struct Node* newNode = createNode(val);
    if (!root) return newNode;

    struct Node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        struct Node* temp = queue[front++];

        if (!temp->left) {
            temp->left = newNode;
            break;
        } else queue[rear++] = temp->left;

        if (!temp->right) {
            temp->right = newNode;
            break;
        } else queue[rear++] = temp->right;
    }
    return root;
}

// Delete a node (replace with deepest node)
void deleteNode(struct Node** root, int key) {
    if (!*root) return;

    struct Node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = *root;
    struct Node *keyNode = NULL, *temp, *last, *parent = NULL;

    while (front < rear) {
        temp = queue[front++];
        if (temp->data == key) keyNode = temp;
        if (temp->left) {
            parent = temp;
            queue[rear++] = temp->left;
        }
        if (temp->right) {
            parent = temp;
            queue[rear++] = temp->right;
        }
    }

    if (!keyNode) {
        printf("Value not found!\n");
        return;
    }

    last = temp;
    keyNode->data = last->data;
    if (parent->right == last) parent->right = NULL;
    else parent->left = NULL;
    free(last);
    printf("Deleted %d\n", key);
}

// Traversals
void inorder(struct Node* r){ if(r){ inorder(r->left); printf("%d ",r->data); inorder(r->right);} }
void preorder(struct Node* r){ if(r){ printf("%d ",r->data); preorder(r->left); preorder(r->right);} }
void postorder(struct Node* r){ if(r){ postorder(r->left); postorder(r->right); printf("%d ",r->data);} }

// Display tree sideways
void display(struct Node* r, int space) {
    if (!r) return;
    space += 5;
    display(r->right, space);
    printf("\n");
    for (int i = 5; i < space; i++) printf(" ");
    printf("%d\n", r->data);
    display(r->left, space);
}

int main() {
    struct Node* root = NULL;
    int ch, val;

    while (1) {
        printf("\n1.Insert 2.Delete 3.Display 4.Inorder 5.Preorder 6.Postorder 7.Exit\nChoice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: printf("Value: "); scanf("%d", &val); root = insert(root, val); break;
            case 2: printf("Delete: "); scanf("%d", &val); deleteNode(&root, val); break;
            case 3: printf("\nTree:\n"); display(root, 0); break;
            case 4: printf("Inorder: "); inorder(root); printf("\n"); break;
            case 5: printf("Preorder: "); preorder(root); printf("\n"); break;
            case 6: printf("Postorder: "); postorder(root); printf("\n"); break;
            case 7: exit(0);
            default: printf("Invalid!\n");
        }
    }
}