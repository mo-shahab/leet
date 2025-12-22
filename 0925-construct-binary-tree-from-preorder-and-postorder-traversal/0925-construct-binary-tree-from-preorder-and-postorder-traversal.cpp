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
    // Using a map for O(1) lookups to keep it O(N) total
    unordered_map<int, int> postMap;

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        for (int i = 0; i < postorder.size(); i++) {
            postMap[postorder[i]] = i;
        }
        int index = 0;
        return helper(preorder, postorder, index, 0, postorder.size() - 1);
    }

    TreeNode* helper(vector<int>& preorder, vector<int>& postorder, int& index, int left, int right) {
        // Base case: no more nodes or out of range
        if (index >= preorder.size() || left > right) return nullptr;

        TreeNode* node = new TreeNode(preorder[index++]);

        // If this was a leaf node or the only node in the range, we stop here
        if (left == right || index >= preorder.size()) return node;

        // The next element in preorder is the root of the left subtree
        int leftSubtreeRootVal = preorder[index];
        int postIdx = postMap[leftSubtreeRootVal];

        // The left subtree exists in postorder from [left] to [postIdx]
        node->left = helper(preorder, postorder, index, left, postIdx);
        
        // The right subtree exists from [postIdx + 1] to [right - 1]
        // We use 'right - 1' because 'right' is the current node's value!
        node->right = helper(preorder, postorder, index, postIdx + 1, right - 1);

        return node;
    }
};