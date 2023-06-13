// Leetcode 337 House robbers 3   @devottam2809

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
pair<int,int>p={0,0};
pair<int,int> helper(TreeNode* root){
    if(root==nullptr)
        return p;

        pair<int,int>left=helper(root->left);
        pair<int,int>right=helper(root->right);

        int yes=root->val+left.second+right.second;
        int no=max(left.first,left.second)+max(right.first,right.second);
        
    return {yes,no};
}

public:
    int rob(TreeNode* root) {
        pair<int,int>ans=helper(root);
    int t=max(ans.first,ans.second);
return t;
    }
};
