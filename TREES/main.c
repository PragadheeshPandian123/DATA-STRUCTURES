#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int SIZE = 100;  
int n;

int check_n(int n)
{
    int narr[] = {1,3,7,15,31,63};
    for(int i=0;i<6;i++)
    {
        if(n<narr[i] || n==narr[i])
        {
            n = narr[i];
            return n;
        }
    }
}
void display(int n)
{
    n = check_n(n);
    int idx = 0;
    char ch = 'a';
    int level = 0;
    while(idx<n)
    {
        int nnodes = (int)pow(2,level);
        for(int s=0;s<(n-nnodes);s++)
        {
            printf(" ");
        }
        for(int i=0;i<nnodes && idx<n;i++)
        {
            printf("%c ",ch+idx);
            idx++;
        }
        printf("\n\n");
        level++;
    }
}
void display_tree(int tree[],int n)
{
    printf("\n\n");
     n = check_n(n);
    int idx = 0;
    int level = 0;
    while(idx<n)
    {
        int nnodes = (int)pow(2,level);
        for(int s=0;s<(n-nnodes);s++)
        {
            printf(" ");
        }
        for(int i=0;i<nnodes && idx<n;i++)
        {
            if(tree[idx]!=-1)
            printf("%d ",tree[idx]);
            else
            printf(" ");
            idx++;
        }
        printf("\n\n");
        level++;
    }
}
void create_tree(int tree[],int n)
{
    printf("enter only %d elements:\n",n);
    n = check_n(n);
    char ch = 'a';
    for(int i=0;i<n;i++)
    {
        printf("enter %c:",ch+i);
        scanf("%d",&tree[i]);
    }

}
void insert_node(int tree[], int n,int val) {
    n = check_n(n);
    for (int i = 0; i < n; i++) {
        if (tree[i] == -1) {   
            tree[i] = val;
            printf("Inserted %d at position %d\n", val, i);
            return;
        }
    }
    printf("Tree is full, cannot insert %d\n", val);
}
void delete_node(int tree[],int n,int val) {
    n = check_n(n);
    int i, found = -1;

    for (i = 0; i < n; i++) {
        if (tree[i] == val) {
            found = i;
            break;
        }
    }

    if (found == -1) {
        printf("Value %d not found!\n", val);
        return;
    }

    for (i = found; i < n - 1; i++) {
        tree[i] = tree[i + 1];
    }
    n--;

}

void inorder(int tree[],int n,int i)
{
    if(i>=n) return;
    inorder(tree,n,2*i +1);
    if(tree[i]!=-1)
        printf("%d ",tree[i]);
    else 
        printf("");
    inorder(tree,n,2*i +2);
}
void preorder(int tree[],int n,int i)
{
    if(i>=n) return;
    if(tree[i]!=-1)
        printf("%d ",tree[i]);
    else 
        printf("");
    preorder(tree,n,2*i +1);
    
    preorder(tree,n,2*i +2);
}
void postorder(int tree[],int n,int i)
{
    if(i>=n) return;
    
    postorder(tree,n,2*i +1);
    
    postorder(tree,n,2*i +2);
    if(tree[i]!=-1)
        printf("%d ",tree[i]);
    else 
        printf("");
}
void traversal(int tree[],int n)
{
    int ch;
    printf("\nenter the traversal choice:\n1.inorder\n2.preorder\n3.postorder\n");
    printf("enter your choice:\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
            printf("\ninorder traversal:");
            inorder( tree, n,0);
            break;
        case 2:
            printf("\npreorder traversal:");

            preorder(tree,n,0);
            break;
        case 3:
            printf("\npostorder traversal:");
            postorder(tree,n,0);
            break;
    }
}
int main()
{
    int tree[SIZE];
    printf("enter the maximum number of nodes you would like to enter:");
    scanf("%d",&n);
    display(n);
    int ch;
    int val;
    do
    {
            printf("\n\nbinary tree operations\n");

        printf("1.Creation\n2.Insertion\n3.Deletion\n4.Display\n5.Traversals\n0.Exit");
        printf("\n\nenter your choice:");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                printf("enter the elements according to the structure of tree(enter -1 for empty):\n");
                create_tree(tree,n);
                break;
            case 2:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                insert_node(tree,n,val);
                break;
            case 3:
                 printf("Enter value to delete: ");
                scanf("%d", &val);
                delete_node(tree,n,val);
                break;
            case 4:
                display_tree(tree,n);
                break;
            case 5:
                traversal(tree,n);
                break;
                
        }
    } while (ch!=0);
    
    
    
}