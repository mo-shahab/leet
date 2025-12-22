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

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() != inorder.size()) return nullptr;

        for(int i = 0; i < inorder.size(); i++) {
            map[inorder[i]] = i;
        }

        /**
        * the pointers used in here 
        * index-> tracks the preorder array
        * left, right -> tracks the inorder array 
        */
        int index = 0;

        return helper(preorder, inorder, 0, inorder.size() -1, index, map);
    }

    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int left, int right, int& index, unordered_map<int, int>& map) {
        if( left > right) return nullptr;

        int curr = preorder[index++];

        TreeNode* node = new TreeNode(curr);

        if(left == right) return node;

        int inorderIndex = map[curr];

        node->left = helper(preorder, inorder, left, inorderIndex -1,  index, map);
        node->right = helper(preorder, inorder, inorderIndex + 1, right,  index, map);

        return node;
    }
};