#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//structure of tree node
struct node
{
    int data;
    struct node *left, *right;    
};

//creating new tree node
struct node *newNode(int element)
{
    struct node *node= (struct node*)malloc(sizeof(struct node));
    node->data = element;
    node->left= NULL;
    node->right= NULL;
    return(node);
}

//inorder transversal of BST always gives sorted output
void inorder(struct node *root)
{
    if(root != NULL)
    {
        inorder(root ->left);
        printf(" %d", root->data);
        inorder(root->right); 
    }
}

struct node* search(struct node* root, int key)
{
    if(root == NULL || root->data==key)
        return root;
    if(root->data < key)
        return search(root->right,key);
    else 
        return search(root->left,key);
}

struct node* insert(struct node* node,int data)
{
    if(node==NULL) 
    { return newNode(data); }

    if(data < node->data)
    {
        node->left= insert(node->left, data);
    }

     if(data > node->data)
    {
        node->right= insert(node->right, data);
    }
    return (node);
}

int main()
{
    int key;
    struct node* x;
    struct node *base= NULL;
    base= insert(base,50);
    insert(base,20);
    insert(base,63);
    insert(base,30);
    insert(base,70);
    insert(base,18);

    printf("Enter the key: ");
    scanf("%d",&key);

    x=search(base,key);

    if(x== NULL)
    {
        printf("Key not present");
    }
    else
    {
        printf("Key Present");
    }
    

}

