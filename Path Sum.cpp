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
private:
    bool isPathSum(TreeNode *root, pair<vector<int>, int> &p, int targetSum) {
        if (!root)
            return false;

        // Add the current node's value to the path and update the current sum.
        p.first.push_back(root->val);
        p.second += root->val;

        // Check if it's a leaf node and the current sum equals the target sum.
        if (!root->left && !root->right && p.second == targetSum)
            return true;

        // Recursively check left and right subtrees.
        if (isPathSum(root->left, p, targetSum))
            return true;
        if (isPathSum(root->right, p, targetSum))
            return true;

        // Backtrack: remove the current node from the path and update the sum.
        p.first.pop_back();
        p.second -= root->val;

        return false;
    }

public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        pair<vector<int>, int> p(path, 0);
        return isPathSum(root, p, targetSum);
    }
};
