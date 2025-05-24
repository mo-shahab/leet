#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

void dfs_recursive(){
    visited[node] = true;
    
    cout << node << " ";

    for(int neighbor: adjacent[node]){
        if(!visited[neighbor]){
            dfs_recursive(adjacent);
        }
    }

}

int main() {
    int n = 6; // Number of nodes (0 to 5)
    vector<vector<int>> adj(n);

    // Undirected graph edges
    adj[0] = {1, 2};
    adj[1] = {0, 3, 4};
    adj[2] = {0, 5};
    adj[3] = {1};
    adj[4] = {1};
    adj[5] = {2};

    vector<bool> visited(n, false);

    cout << "BFS Iterative: ";
    bfs_iterative(0, adj, visited);
    cout << endl;

    return 0;
}
