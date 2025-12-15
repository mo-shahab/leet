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
    ListNode* merge(ListNode* left, ListNode* right){
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;

        while(left && right) {
            if(left->val < right->val) {
                temp->next = left;
                left = (*left).next;
            } else {
                temp->next = right;
                right = (*right).next;
            }
            temp = temp->next;
        }

        while(left) {
            temp->next = left;
            left = left->next;
            temp = temp->next;
        }

        while(right) {
            temp->next = right;
            right = right->next;
            temp = temp->next;
        }

        return dummy->next;
    }

    ListNode* mergeSort(vector<ListNode*>& lists, int low, int high) {
        if(low == high) {
            return lists[low];
        }

        int mid = low + (high-low) / 2;
        ListNode* left = mergeSort(lists, low, mid);
        ListNode* right = mergeSort(lists, mid+ 1, high);

        return merge(left, right);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) {
            return nullptr;
        }

        return mergeSort(lists, 0, lists.size() - 1);
    }

};