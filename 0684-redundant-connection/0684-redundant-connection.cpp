class UnionFind {
    vector<int> root, rank;
public:
    UnionFind(int n){
        rank.assign(n, 1);
        root.resize(n); // Corrected: Resize the root vector
        iota(root.begin(), root.end(), 0);
    }

    int Find(int x){
        if(x == root[x]) return x;
        else return root[x] = Find(root[x]);
    }

    bool Union(int x, int y) {
        int rootX = Find(x);
        int rootY = Find(y);
    
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                root[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                root[rootX] = rootY;
            } else {
                root[rootY] = rootX;
                rank[rootX]++;
            }
            return true;
        }
        return false;
    }
};

class Solution {
public:

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        const int n=edges.size();
        UnionFind G(n+1);
        for(auto& e: edges)
            if (!G.Union(e[0], e[1])) return e;
        return {}; 
    }
};