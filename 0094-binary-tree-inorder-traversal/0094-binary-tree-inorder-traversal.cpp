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
    void inorder(TreeNode* root, vector<int> &order) {
        if(!root) return;

        inorder(root->left, order);
        order.push_back(root->val);
        inorder(root->right, order);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> order;
        
        inorder(root, order);

        return order;
    }
};