#include <bits/stdc++.h>
#include <stdlib.h>
#include <vector>

using namespace std;

struct node{
    int data;
    node *left;
    node *right;
};

node *head_node(int data)
{
    node *newnode=(node *)malloc(sizeof(node));
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
return newnode;
}

node *push(node *root,int data)
{
    if(root==NULL)
        return head_node(data);
    if(data<root->data)
        root->left=push(root->left,data);
    else if(data>root->data)
        root->right=push(root->right,data);
return root;
}

void print_LVL(node *root)
{
    vector<int>nums;
    if(root==NULL)
        return ;
    queue<node*>q;
    q.push(root);
    while(q.empty()==false)
    {
        node *node=q.front();
        cout<<node->data<<" ";
        //nums.push_back(node->data);
        q.pop();

        if(node->left!=NULL)
            q.push(node->left);
        
        if(node->right!=NULL)
            q.push(node->right);
    }
//for(int i=0;i<nums.size();i++)
  //  cout<<nums[i]<<" ";
}

void inorder(node *root)
{
    if(!root)
        return ;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main()
{
    node *root=NULL;
    root=head_node(9);
    push(root,5);
    push(root,3);
        push(root,1);
            push(root,6);
                push(root,10);
inorder(root);
cout<<"\n";
print_LVL(root);
    return 0;
}
