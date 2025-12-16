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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;
        if(!p || !q) return false;

        queue<TreeNode*> q1;
        queue<TreeNode*> q2;

        q1.push(p);
        q2.push(q);

        while(!q1.empty() && !q2.empty()){

            TreeNode* curr1 = q1.front();
            TreeNode* curr2 = q2.front();

            q1.pop();
            q2.pop();

            if(curr1->val != curr2->val) return false;

            if(curr1->left && curr2->left) {
                q1.push(curr1->left);
                q2.push(curr2->left);
            } else if (curr1->left || curr2->left){
                return false;
            }
            else {
            }


            if(curr1->right && curr2->right) {
                q1.push(curr1->right);
                q2.push(curr2->right);
            } else if (curr1->right || curr2->right){
                return false;
            }
            else {
            }
        }

        return true;
    }

};