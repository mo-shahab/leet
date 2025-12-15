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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0, head);

        ListNode* after = head;
        ListNode* before = dummy;
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* next = nullptr;

        while(true){
            ListNode* cursor = after;

            // checking if there are atleast k number of nodes before doing anything
            for(int i = 0; i < k; i++){
                if(cursor == nullptr) return dummy->next;
                cursor = cursor->next;
            }

            /**
            * in place reversal of the nodes
            */
            curr = after; // will start at the start of the group
            prev = before; // tail of the previous group

            // algo for the reversal of the thing nothing new
            for(int i = 0; i < k; i++){
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }

            // curr has reached end
            // tail of the current group is the head of the next group
            after->next = curr;
            before->next = prev;
            before = after;
            after = curr;
        }

        return dummy->next;
    }

};

