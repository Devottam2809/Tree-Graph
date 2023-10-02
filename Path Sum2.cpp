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
vector<vector<int>> ans;
private:
    void isPathSum(TreeNode *root, pair<vector<int>, int> &p, int targetSum) {
        if (!root)
            return ;

        p.first.push_back(root->val);
        p.second += root->val;

        if (!root->left && !root->right && p.second == targetSum)
            ans.push_back(p.first);

        isPathSum(root->left, p, targetSum);

        isPathSum(root->right, p, targetSum);
            
        p.first.pop_back();
        p.second -= root->val;
    }

public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        pair<vector<int>, int> p(path, 0);
        isPathSum(root, p, targetSum);
    return ans;
    }
};

