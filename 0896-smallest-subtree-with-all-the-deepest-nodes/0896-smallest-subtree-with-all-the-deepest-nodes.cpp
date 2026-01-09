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
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;

        int left = maxDepth(root->left);
        int right = maxDepth(root->right);

        int depth = 1 + max(left, right);

        return depth;
    }

    TreeNode* dfs(TreeNode* root, int depth, int currentMax) {
        if(root == nullptr) return nullptr;
        if(currentMax == depth - 1) return root;

        TreeNode* left = dfs(root->left, depth, currentMax + 1); 
        TreeNode* right = dfs(root->right, depth, currentMax + 1);

        if(left && right) return root;
        return left ? left: right;
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        int depth = maxDepth(root);

        return dfs(root, depth, 0);
    }
};