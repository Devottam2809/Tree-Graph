#include <iostream>
#include <stdlib.h>

using namespace std;

struct node{
    int data;
    node *left,*right;
};

node *head_node(node *root,int data)
{
    node *temp=(node *)malloc(sizeof(node));
    temp->data=data;
    temp->left=temp->right=NULL;
return temp;
}

node *push(node *root,int data)
{
    if(!root)
        return head_node(root,data);
    if(data<root->data)
        root->left=push(root->left,data);
    else if(data>root->data)
        root->right=push(root->right,data);

    return root;
}

void inordertraversal(node *root)
{
    if(!root)
        return ;
    inordertraversal(root->left);
        cout<<root->data<<"\t";
    inordertraversal(root->right);
}

void preorder(node *root)
{
    if(!root)
        return;
    cout<<root->data<<"\t";
    preorder(root->left);
    preorder(root->right);
}

void postorder(node *root)
{
    if(!root)
        return;
    
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<"\t";
}
int main()
{
    cout<<"1 . Inorder Traversal\n 2. Preorder Traversal\n 3. Postorder Traversal\n";
    int choice;
    cout<<"Enter the choice";
    cin>>choice;
    cout<<"Enter the choice";

    node *root=NULL;
    int n;
    cout<<"Enter the number of nodes : ";
    cin>>n;

    int head_data;
    cout<<"Enter the head data : ";
    cin>>head_data;
    root=head_node(root,head_data);

    for(int i=0;i<n-1;i++)
    {
        int element;
        cin>>element;
        push(root,element);
    }
    
    if(choice==1)
    {
        cout<<"INORDER TRAVERSAL"<<endl;
        inordertraversal(root);
        cout<<"\n";
    }
    
    else if(choice==2)
    {
        cout<<"PREORDER TRAVERSAL"<<endl;
        preorder(root);
        cout<<"\n";
    }
    else if(choice == 3)
    {
        cout<<"POST ORDER TRAVERSAL"<<endl;
        postorder(root);
    }
    else    
        cout<<"Invalid Choice";
    
    return 0;
}
