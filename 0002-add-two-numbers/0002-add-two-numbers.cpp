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
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // things i need to think of, or take care of
        // 1. carry
        // 2. the lists length

        ListNode* dummy = new ListNode(0); // this will be used to return 
        ListNode* curr = dummy; // this will be used for the list manipulation
        int carry = 0;

        while(l1 || l2 || carry != 0)  {
            int val1 = l1 ? l1->val : 0;
            int val2 = l2 ? l2->val : 0;

            int sum = val1 + val2 + carry;

            int digit = sum % 10; // this will return digit
            carry = sum / 10;

            ListNode* node = new ListNode(digit);
            curr->next = node;
            curr = curr->next;

            l1 = l1 ? l1->next : 0;
            l2 = l2 ? l2->next : 0;
        }

        return dummy->next;
    }

};