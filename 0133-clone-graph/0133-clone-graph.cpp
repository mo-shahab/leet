/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;

        Node* copy = new Node(node->val, {});
        unordered_map<Node*, Node*> visited;

        queue<Node*> q;
        q.push(node);
        visited[node] = copy;
        
        while(!q.empty())
        {
            Node* curr = q.front();
            q.pop();

            for(Node* neighbor: curr->neighbors)
            {
                if(!visited[neighbor])
                {
                    Node* new_neighbor = new Node(neighbor->val);
                    visited[neighbor] = new_neighbor;
                    q.push(neighbor);
                }
                visited[curr]->neighbors.push_back(visited[neighbor]);
            }
        }

        return visited[node];
    }
};