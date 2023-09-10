#include <bits/stdtr1c++.h>
using namespace std;

struct node{
    int val;
    node *left;
    node *right;
    node(int x){
        val=x;
        left=right=nullptr;
    }
};

int height(node *root){
    if(root==nullptr)
        return 0;
    int left=height(root->left);
    int right=height(root->right);
return max(left,right)+1;
}

// METHOD 1

bool isBalanced1(node* root) {
    if(root==nullptr)
        return root;
    bool first=isBalanced1(root->left);
    bool second=isBalanced1(root->right);
    bool third=abs(height(root->left)-height(root->right))<=1;
    if(first and second and third)
        return true;
    return false;
}

// METHOD 2
pair<bool,int> isBalanced2(node *root){
    if(root==nullptr){
        pair<bool,int>p=make_pair(true,0);
        return p;
    }

    pair<bool,int>left=isBalanced2(root->left);
    pair<bool,int>right=isBalanced2(root->right);

    bool leftans=left.first;
    bool rightans=right.first;
    bool diff=abs(left.second-right.second)<=1;

    pair<bool,int>ans;
    ans.second=max(left.second,right.second)+1;
    if(leftans and rightans and diff)
        ans.second=true;
    else    
        ans.second=false;

return ans;
}

int main()
{
    node *root=new node(1);
    root->left=new node(2);
    root->left->left=new node(3);
    root->left->right=new node(4);
    root->left->right->left=new node(5);;
    root->left->right->right=new node(6);
    root->right=new node(7);
    root->right->right=new node(8);
    root->right->right->right=new node(9);
    root->right->right->right->right=new node(10);

   cout<<isBalanced1(root);
   cout<<isBalanced2(root).first;
    return 0;
}
