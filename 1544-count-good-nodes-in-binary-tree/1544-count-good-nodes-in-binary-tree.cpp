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
    int dfs(TreeNode* root, int currentMax) {
        if(!root) return 0;

        int count = 0;

        if(root->val >= currentMax) {
            count = 1;
            currentMax = root->val;
        }

        return count + dfs(root->left, currentMax) + dfs(root->right, currentMax);
    }

    int goodNodes(TreeNode* root) {
        return dfs(root, INT_MIN);
    }
};