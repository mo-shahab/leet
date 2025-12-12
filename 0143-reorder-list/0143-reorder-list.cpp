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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* curr = slow->next;
        slow->next = nullptr;
        ListNode* next = nullptr;
        ListNode* prev = nullptr;
        ListNode* temp1 = nullptr;
        ListNode* temp2 = nullptr;

        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }


        while(head && prev) {
            temp1 = head->next; // store the next node from the first unreversed half
            temp2 = prev->next; // store the next node from the second reversed half

            head->next = prev;
            prev->next = temp1;

            head = temp1;
            prev = temp2;
        }
    }
};