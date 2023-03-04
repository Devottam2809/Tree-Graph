#include <stdio.h>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

struct node{
    int data;
    node *left;
    node *right;
};

int height(node *root)
{
    if(root==NULL)
        return 0;
    int lheight=height(root->left);
    int rheight=height(root->right);
return max(lheight,rheight)+1;
}

void printlevel_order(node *root,int level)
{
    if(root==NULL)
        return ;
    if(level==1)
        cout<<root->data<<" ";
    else if(level>1)
    {
        printlevel_order(root->left,level-1);
        printlevel_order(root->right,level-1);
    }
}

node *head_node(int data)
{
    node *newnode=(node *)malloc(sizeof(node));
    newnode->data=data;
    newnode->left=newnode->right=NULL;
return newnode;
}

node *push(node *root,int data)
{
    if(root == NULL)
        return head_node(data);
    else if(data < root->data)
        root->left=push(root->left,data);
    else if(data>root->data)
        root->right=push(root->right,data);
return root;
}

void inorder(node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

int main()
{
    vector<int>nums;
    node *root=NULL;
    root=head_node(1);
    push(root,9);
    push(root,20);
    push(root,15);
    push(root,7);

    for(int i=0;i<=height(root);i++)
        printlevel_order(root,i);
    return 0;
}
