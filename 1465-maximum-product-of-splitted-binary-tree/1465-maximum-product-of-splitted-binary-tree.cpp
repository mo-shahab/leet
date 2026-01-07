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

    int dfsTotalSum(TreeNode* root) {
        if(!root) return 0;
        int left = dfsTotalSum(root->left);
        int right = dfsTotalSum(root->right);

        return root->val + left + right;
    }

    int dfsSubtreeSum(TreeNode* root, long long& maxProd, long long totalSum) {
        if(!root) return 0;

        int left = dfsSubtreeSum(root->left, maxProd, totalSum);
        int right = dfsSubtreeSum(root->right, maxProd, totalSum);

        int subtreeSum = root->val + left + right;

        maxProd = max(maxProd, subtreeSum * (totalSum - subtreeSum));
        return subtreeSum;
    }

    int maxProduct(TreeNode* root) {
        int res;
        long long maxProd = 1;
        long long totalSum = dfsTotalSum(root);

        dfsSubtreeSum(root, maxProd, totalSum);

        res =  int(maxProd % (int(pow(10, 9)) + 7));

        return res;
    }
};