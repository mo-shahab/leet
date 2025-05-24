#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

void dfs_recursive(int node, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;
    cout << node << " ";

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs_recursive(neighbor, adj, visited);
        }
    }
}

// void dfs_recursive(int node, vector<vector<int>>& adj, vector<boo>& visited){
//     visited[node] = true;
//     cout << node << " ";
//
//     for(int neighbor: adj[node]){
//         if(!visited[neighbor]){
//             dfs_recursivev(neighbor, adj, visited);
//         }
//     }
// }

void dfs_iterative(int start, vector<vector<int>>& adj, vector<bool>& visited) {
    stack<int> st;
    st.push(start);

    while (!st.empty()) {
        int node = st.top(); st.pop();
        if (visited[node]) continue;

        visited[node] = true;
        cout << node << " ";

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                st.push(neighbor);
            }
        }
    }
}

// Iterative BFS
void bfs_iterative(int start, vector<vector<int>>& adj, vector<bool>& visited) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front(); q.pop();
        cout << node << " ";

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

// Sample usage
int main() {
    int n = 6; // Number of nodes (0 to 5)
    vector<vector<int>> adj(n);

    // Undirected graph edges
    adj[0] = {2, 1};
    adj[1] = {0, 3, 4};
    adj[2] = {0, 5};
    adj[3] = {1};
    adj[4] = {1};
    adj[5] = {2};

    vector<bool> visited(n, false);

    cout << "DFS Recursive: ";
    dfs_recursive(0, adj, visited);
    cout << endl;

    fill(visited.begin(), visited.end(), false);
    cout << "DFS Iterative: ";
    dfs_iterative(0, adj, visited);
    cout << endl;

    fill(visited.begin(), visited.end(), false);
    cout << "BFS Iterative: ";
    bfs_iterative(0, adj, visited);
    cout << endl;

    return 0;
}

