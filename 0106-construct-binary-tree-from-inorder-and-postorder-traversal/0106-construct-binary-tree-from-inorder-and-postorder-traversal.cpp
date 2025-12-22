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
    unordered_map<int, int> map;

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() != postorder.size()) return nullptr;

        for(int i = 0; i < inorder.size(); i++) map[inorder[i]] = i;

        int index = inorder.size() -1;
        return  helper(inorder, postorder, 0, inorder.size() -1, index, map);
    }

    TreeNode* helper(vector<int>& inorder, vector<int>& postorder, int left, int right, int& index, unordered_map<int, int>& map) {
        if(left > right) return nullptr;

        int curr = postorder[index--];

        TreeNode* node = new TreeNode(curr);
        if(left == right) return node;

        int inorderIndex = map[curr];

        node->right = helper(inorder, postorder, inorderIndex + 1, right, index, map);
        node->left = helper(inorder, postorder, left, inorderIndex - 1, index, map);

        return node;
    }

};