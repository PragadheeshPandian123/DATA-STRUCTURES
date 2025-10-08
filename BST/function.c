# include <stdio.h>
# include <stdlib.h>

typedef struct node 
{
    int data;
    struct node * left;
    struct node * right;
} Node;


Node * create_Root(int val){
    Node * newNode=(Node *)malloc(sizeof(Node));
    newNode->data=val;
    newNode->left=newNode->right=NULL;
    return newNode;
}

Node * insert(Node *root,int val)
{
    if(!(root))
    {
        Node * newNode=(Node * )malloc(sizeof(Node));   
        newNode->data=val;
        newNode->left=newNode->right=NULL;
        root=newNode;
    }
    else{
        if(val<(root)->data){
            root->left=insert((root)->left,val);
        }
        else
        {
            root->right=insert((root)->right,val);
        }
    }
    return root;
}

Node * findLargestNode(Node * root){
    if(root==NULL || root->right==NULL){
        return root;
    }
    else{
        return findLargestNode(root->right);
    }
}


Node * delete(Node *root,int val)
{
    if(!(root))
    {
        return NULL;
    }
    else if((root)->data < val){
        (root)->right=delete((root)->right,val);
    }
    else if((root)->data > val){
        (root)->left=delete((root)->left,val);
    }
    else{
        if((root)->left == NULL && (root)->right==NULL){
            free(root);
            return NULL;
        }
        else if((root)->left!=NULL && (root)->right!=NULL){
            Node * temp=findLargestNode((root)->left);
            (root)->data=temp->data;
            root->left=delete(root->left,root->data);
        }
        else if ((root)->left!=NULL)
        {
            Node * temp=(root)->left;
            free(root);
            return temp;
        }
        else if((root)->right!=NULL){
            Node * temp=(root)->right;
            free(root);
            return temp;
        }
    }
    return root;
}

void inorder(Node *root){
    if(root!=NULL){
        inorder((root)->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

void preorder(Node * root){
    if(root!=NULL)
    {
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node * root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}

void displayTree(Node* root) {
    if (!root) {
        printf("Tree is empty!\n");
        return;
    }

    Node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        int nodeCount = rear - front;
        int allNullInLevel = 1;

        for (int i = front; i < rear; i++) {
            if (queue[i] != NULL) {
                allNullInLevel = 0;
                break;
            }
        }
        if (allNullInLevel) break;

        for (int i = 0; i < nodeCount; i++) {
            Node* curr = queue[front++];
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