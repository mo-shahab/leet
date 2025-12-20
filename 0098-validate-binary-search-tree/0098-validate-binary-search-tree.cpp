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

    bool isValidBST(TreeNode* root) {

        long prev = LLONG_MIN;
        vector<int> order;

        inorder(root, order);

        for(int i = 0; i < order.size(); i++) {
            if(order[i] <= prev) return false;
            prev = order[i];
        }

        return true;
    }
};