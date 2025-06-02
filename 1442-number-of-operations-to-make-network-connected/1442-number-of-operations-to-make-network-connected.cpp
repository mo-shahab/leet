class UnionFind{
public:
    vector<int> parent, rank;
    int count;

    UnionFind(int n){
        parent.resize(n);
        rank.assign(n, 1);
        count = n;

        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
    }

    int find(int node){
        if(parent[node] == node){
            return node;
        }

        else return parent[node] = find(parent[node]);
    }

    int Union(int x, int y){
        int rx = find(x), ry = find(y);
        if(rx == ry) return 0;

        if(rank[rx] > rank[ry]){
            parent[ry] = rx;
        } else if(rank[rx] < rank[ry]){
            parent[rx] = ry;
        } else {
            parent[rx] = ry;
            rank[ry]++;
        }

        count--;
        return 1;
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1)
            return -1; 
    
        UnionFind G(n);
        for (auto& e : connections)
            G.Union(e[0], e[1]);
    
        return G.count - 1;
    }
};