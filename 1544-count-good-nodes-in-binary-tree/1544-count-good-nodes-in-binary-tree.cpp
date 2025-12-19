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
// root: the node we are looking at right now
// currentMax: the biggest value we saw on the path FROM the root TO this node's parent
int dfs(TreeNode* root, int currentMax) {
    if(!root) return 0; // If we hit a dead end, we found 0 good nodes.

    int count = 0;

    // STEP 1: Is the current node "Good"?
    // We compare it to the biggest thing we've seen so far on this path.
    if(root->val >= currentMax) {
        count = 1;              // It's a good node!
        currentMax = root->val; // Update the record for all nodes BELOW this one.
    }

    // STEP 2: The branching
    // We tell the Left child: "Here is the max value from the path above you."
    // We tell the Right child: "Here is the max value from the path above you."
    return count + dfs(root->left, currentMax) + dfs(root->right, currentMax);
}

    int goodNodes(TreeNode* root) {
        return dfs(root, INT_MIN);
    }
};