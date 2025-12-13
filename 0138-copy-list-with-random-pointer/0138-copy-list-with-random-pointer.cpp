/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> hashmap;

        Node* curr = head;

        while(curr){
            hashmap[curr] = new Node(curr->val);
            curr = curr->next;
        }

        curr = head;

        while(curr) {
            Node* copy = hashmap[curr];
            copy->next = hashmap[curr->next];
            copy->random = hashmap[curr->random];
            curr = curr->next;
        }

        return hashmap[head];
    }
};
