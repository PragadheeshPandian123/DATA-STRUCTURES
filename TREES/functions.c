# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# define MAX 100
typedef struct node 
{
    struct node * left;
    int data;
    struct node * right;
}Node;

Node * root=NULL;

Node * queue[100];
int front=-1,rear=-1;

void push(Node * node)
{
    if(rear==MAX-1)
    {
        printf("Underflow\n");
        return;
    }
    else{
        if(front==-1 && rear==-1){
            rear++,front++;
            queue[rear]=node;
        }
        else
        {
            rear++;
            queue[rear]=node;
        }
    }
}

Node * pop()
{
    if(front==-1 || front > rear)
    {
        printf("Underflow\n");
        return NULL;
    }
    else
    {
        Node * node=queue[front];
        front=front+1;
        if(front>rear)
        {
            front=rear=-1;
        }
        return node;
    }
}

void createTree()
{
    Node * newNode=(Node *)malloc(sizeof(Node));
    int val;
    printf("Enter data: ");
    scanf("%d",&val);
    newNode->data=val;
    newNode->left=newNode->right=NULL;
    root=newNode;
}

int isEmpty()
{
    if(front==-1)return 1;
    else return 0;
}

void insert()
{
    if(root==NULL)
    {
        createTree();
        return;
    }
    Node * newNode=(Node *)malloc(sizeof(Node));
    int val;
    printf("Enter the value: ");
    scanf("%d",&val);

    newNode->data=val;
    newNode->left=newNode->right=NULL;
    push(root);
    while(!isEmpty())
    {
        Node * curr=pop();
        if(curr->left==NULL)
        {
            curr->left=newNode;
            break;
        }
        else{
            push(curr->left);
        }

        if(curr->right==NULL)
        {
            curr->right=newNode;
            break;
        }
        else
        {
            push(curr->right);
        }
    }
    front=rear=-1;
}   

void inorder(Node * root)
{
    if(root)
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

void preorder(Node * root)
{
    if(root)
    {
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node * root)
{
    if(root)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}


int height(Node* root) {
    if (root == NULL) return 0;
    int left = height(root->left);
    int right = height(root->right);
    return (left > right ? left : right) + 1;
}

void printSpaces(int n) {
    for (int i = 0; i < n; i++)
        printf(" ");
}

void printLevel(Node* root, int level, int currLevel, int space) {
    if (root == NULL) {
        printSpaces(space);
        printf(" ");
        printSpaces(space);
        return;
    }

    if (level == 1) {
        printSpaces(space);
        printf("%d", root->data);
        printSpaces(space);
    } else if (level > 1) {
        printLevel(root->left, level - 1, currLevel, space);
        printLevel(root->right, level - 1, currLevel, space);
    }
}

void printTreeFancy(Node* root) {
    int h = height(root);
    int space = (int)pow(2, h);  // spacing

    for (int i = 1; i <= h; i++) {
        printSpaces(space / 2);
        printLevel(root, i, i, space / 2);
        printf("\n");

        // Print slashes between levels
        if (i < h) {
            printSpaces(space / 2 - 1);
            for (int j = 0; j < (int)pow(2, i - 1); j++) {
                printf("/");
                printSpaces(space - 2);
                printf("\\");
                printSpaces(space - 2);
            }
            printf("\n");
        }
        space /= 2;
    }
}

int main()
{
    insert();
    insert();
    insert();
    insert();
    insert();
    // insert();

    printf("\nInorder Traversal: ");
    inorder(root);

    printf("\nPreorder Traversal: ");
    preorder(root);

    printf("\nPostorder Traversal: ");
    postorder(root);

    printf("\nThe Tree in Tree form is : \n");
    printTreeFancy(root);
    return 0;
}