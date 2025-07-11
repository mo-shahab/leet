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
// class Solution {
// public:
//     unordered_map<Node*, Node*> visited;
// 
//     Node* cloneGraph(Node* node) {
//         if(!node) return nullptr;
// 
//         if(visited[node]) return visited[node];
// 
//         Node* copy = new Node(node->val, {});
//         visited[node] = copy;
// 
//         for(auto neighbor: node->neighbors)
//         {
//             copy->neighbors.push_back(cloneGraph(neighbor));
//         }
// 
//         return copy;
//     }
// };

//   class Solution {
//   public:
//       Node* cloneGraph(Node* node) {
//           if(!node) return nullptr;
//   
//           Node* copy = new Node(node->val, {});
//           unordered_map<Node*, Node*> visited;
//   
//           queue<Node*> q;
//           q.push(node);
//           visited[node] = copy;
//   
//           while(!q.empty())
//           {
//               Node* curr = q.front();
//               q.pop();
//   
//               for(Node* neighbor: curr->neighbors)
//               {
//                   if(!visited[neighbor])
//                   {
//                       Node* new_neighbor = new Node(neighbor->val);
//                       visited[neighbor] = new_neighbor;
//                       q.push(neighbor);
//                   }
//                   visited[curr]->neighbors.push_back(visited[neighbor]);
//               }
//           }
//   
//           return visited[node];
//       }
//   };

class Solution {
public:
    Node* cloneGraph(Node* node) {
		if(!node) return nullptr;

		Node* copy = new Node(node->val, {});
		unordered_map<Node*, Node*> visited;
		queue<Node*> q;
		q.push(node);
		visited[node] = copy;

		while(!q.empty()){
			Node* curr = q.front();
			q.pop();	

			for(Node* neigh: curr->neighbors){
				if(!visited[neigh]){
					Node* new_neigh = new Node(neigh->val); 
					visited[neigh] = new_neigh;
					q.push(neigh);
				}

				visited[curr]->neighbors.push_back(visited[neigh]);
			}
		}
        return copy;
	}
};