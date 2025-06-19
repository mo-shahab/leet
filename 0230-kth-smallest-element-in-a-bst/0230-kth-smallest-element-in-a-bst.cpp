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
    vector<int> inorder_elems;

    void inorder(TreeNode* root){
        if (root == nullptr) return;
        inorder(root->left);
        inorder_elems.push_back(root->val);
        inorder(root->right);
    }

    int kthSmallest(TreeNode* root, int k) {
        inorder(root);
        return inorder_elems[k-1];
    }
};