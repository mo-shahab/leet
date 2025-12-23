/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* buildTree(ListNode* head){
        if (head == nullptr) return nullptr;
        if (head->next == nullptr) {
            return new TreeNode(head->val);
        }

        ListNode* prev = nullptr;
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        TreeNode* node = new TreeNode(slow->val);
        ListNode* secondHalf = slow->next;
        if( prev != nullptr) prev->next = nullptr; // cut the linked list
        else {
            head->next = nullptr;
        }

        node->left = buildTree(head);
        node->right = buildTree(secondHalf);

        return node;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        return buildTree(head);
    }
};