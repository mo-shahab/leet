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
    ListNode* deleteMiddle(ListNode* head) {

        if(!head) return nullptr;

        if(head->next == nullptr)  return nullptr;

        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next){
            dummy = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        dummy->next = slow->next;

        return head;
    }
};