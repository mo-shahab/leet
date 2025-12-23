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
public:
    int maxPath = INT_MIN;

    int maxPathSum(TreeNode* root) {
        dfs(root, maxPath);
        return maxPath;
    }

    int dfs(TreeNode* root, int& maxPath) {
        if(!root) return 0;

        int currentPath = root->val;
        int left = max( 0, dfs(root->left, maxPath));
        int right = max(0, dfs(root->right, maxPath));
        maxPath = max(maxPath, currentPath + left + right);

        return  currentPath + max(left, right);
    }

};