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
vector<int>nums;
void helper_Preorder(TreeNode* root,int level){
    if(root==nullptr)
        return ;
    if(level == nums.size())
        nums.push_back(root->val);
    
    helper_Preorder(root->right,level+1);
    helper_Preorder(root->left,level+1);
}
public:
    vector<int> rightSideView(TreeNode* root) {
        helper_Preorder(root,0);
    return nums;
    }
};
