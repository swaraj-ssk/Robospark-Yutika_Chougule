#include<stdio.h>
#include<stdlib.h>


struct node{
    int data;
    struct node  *left, *right;
};


struct node *newNode(int data)
{
    struct node* temp =(struct node*)malloc(sizeof(struct node));
    temp->data= data;
    temp->right= NULL;
    temp->left= NULL;
    return temp;
}

void postorder(struct node* root)
{
    if(root==NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf(" %d",root->data);
}

int main()
{
    struct node *n1  = newNode(1); 
    n1->left         = newNode(2); 
    n1->right        = newNode(3); 
    n1->left->left   = newNode(4); 
    n1->left->right  = newNode(5);
    n1->right->left  = newNode(7);
    n1->right->right = newNode(8);
    printf("\nPostorder traversal : \n");
    postorder(n1);
    
}