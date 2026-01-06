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
    int maxLevelSum(TreeNode* root) {
        if(root == nullptr) return 0;
        if(!root->left && !root->right) return 1;

        queue<TreeNode*> q;
        q.push(root);
        int ans = 1;
        int max_sum = INT_MIN;
        int level = 0;

        while(!q.empty()) {
            int size = q.size();
            int sum_level = 0;
            level++;

            for(int i = 0; i < size; i++) {
                auto curr = q.front();
                q.pop();
                sum_level += curr->val;

                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }

            if(sum_level > max_sum) {
                ans = level;
                max_sum  = sum_level;
            }
        }

        return ans;
    }
};