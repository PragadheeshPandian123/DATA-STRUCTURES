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

void display(Node * root,int space)
{
    if(!root)return;
    space+=5;
    display(root->right,space);
    for(int i=5;i<space;i++)
    {
        printf(" ");
    }
    printf("%d\n",root->data);
    display(root->left,space);
}