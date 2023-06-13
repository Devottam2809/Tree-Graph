// Leetcode 530  Minimum Absolute Difference in BST     @devottam2809

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
private:
void inorder(TreeNode* root){
    if(root){
        inorder(root->left);
        nums.push_back(root->val);
        inorder(root->right);
    }
}
public:
    int getMinimumDifference(TreeNode* root) {
        inorder(root);
        int ans=abs(nums[0]-nums[1]);
    for(int i=0;i<nums.size()-1;i++){
        int m=abs(nums[i]-nums[i+1]);
        ans=min(ans,m);
    }
return ans;
    }
};
