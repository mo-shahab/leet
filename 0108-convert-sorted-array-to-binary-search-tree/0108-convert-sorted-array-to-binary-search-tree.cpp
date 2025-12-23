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
    TreeNode* dfs(vector<int>& nums, int left, int right) {
        if(nums.size() == 0) return nullptr;

        if(left > right) return nullptr;

        int mid = left + (right - left)/2;
        TreeNode* node = new TreeNode(nums[mid]);

        node->left = dfs(nums, left, mid-1);
        node->right = dfs(nums, mid+1, right);

        return node;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return dfs(nums, 0, nums.size() -1);
    }
};