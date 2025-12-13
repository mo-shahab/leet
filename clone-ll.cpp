#include <bits/stdc++.h>

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


Node* cloneList (Node* head) {
    std::unordered_map<Node*, Node*> hashmap;

    Node* curr = head;

    printf("\n--- PHASE 1: Creating New Nodes and Mapping Addresses ---\n");
    while(curr) {
        Node* temp = curr;
        hashmap[curr] = new Node(curr->val);
        
        printf("--> Node Value: %2d | OLD Address: %p | NEW Address: %p\n", curr->val, (void*)temp, (void*)hashmap[curr]);
        
        curr = curr->next;
    }
    
    curr = head;

    printf("\n--- PHASE 2: Setting Pointers on New Nodes ---\n");
    while(curr) {
        Node* copy = hashmap[curr];
        
        Node* oldNext = curr->next;
        Node* oldRandom = curr->random;
        
        copy->next = hashmap[oldNext];
        copy->random = hashmap[oldRandom];

        printf("--> New Node %2d (%p): NEXT is set to %p | RANDOM is set to %p\n", 
               copy->val, 
               (void*)copy, 
               (void*)copy->next, 
               (void*)copy->random
        );
        
        curr = curr->next;
    }

    printf("\n--- Deep Copy Complete. Returning New Head: %p ---\n", (void*)hashmap[head]);
    return hashmap[head];
}

int main () {
    // creating 5 nodes
    Node* first = new Node(7);
    Node* second = new Node(13);
    Node* third = new Node(10);
    Node* fourth = new Node(1);
    Node* fifth = new Node(2);

    // linking them
    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    // some random pointers linking
    first->random = fourth;
    third->random = first;
    second->random = second;

    printf("-> address of the first pointer %p | address of first->next %p | address of first->random %p\n", (void*)first, (void*)first->next, (void*)first->random);
    printf("-> address of the second pointer %p | address of second->next %p | address of second->random %p\n", (void*)second, (void*)second->next, (void*)second->random);
    printf("-> address of the third pointer %p | address of third->next %p | address of third->random %p\n", (void*)third, (void*)third->next, (void*)third->random);
    printf("-> address of the fourth pointer %p | address of fourth->next %p | address of fourth->random %p\n", (void*)fourth, (void*)fourth->next, (void*)fourth->random);
    printf("-> address of the fifth pointer %p | address of fifth->next %p | address of fifth->random %p\n", (void*)fifth, (void*)fifth->next, (void*)fifth->random);

    // running the deepcopy function in here and stuff ??
    Node* copy = cloneList(first);

    return 0;

}
