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

// METHOD 1 for diameter of Tree O(n^2)
int diameter(node *root){
    if(root==nullptr)
        return 0;
    
    int op1=diameter(root->left);
    int op2=diameter(root->right);
    int op3=height(root->left)+height(root->right)+1;
return max(op1,max(op2,op3));
}

// METHOD 2 dor diameter of Tree O(n)
pair<int,int>diam(node *root){
    if(root==nullptr){
        pair<int,int>p=make_pair(0,0);
    return p;
    }

    pair<int,int> left=diam(root->left);
    pair<int,int> right=diam(root->right);

    int op1=left.first;
    int op2=right.first;
    int op3=left.second+right.second+1;

    pair<int,int>ans;
    ans.first=max(op1,max(op3,op2));
    ans.second=max(left.second,right.second)+1;
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

    cout<<diam(root).first;
    cout<<endl;
    cout<<diameter(root);
    return 0;
}
