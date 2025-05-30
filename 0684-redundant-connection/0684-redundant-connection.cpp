class UnionFind { // usual UnionFind class
    vector<int> root, rank;
public:
    UnionFind(int n) : root(n), rank(n) {
        rank.assign(n, 1);
        iota(root.begin(), root.end(), 0);
    }

    int Find(int x) {//Path compression
        if (x == root[x])
            return x;
        else
            return root[x] = Find(root[x]);
    }

    bool Union(int x, int y) {//Union by rank with connecting info
        int rX = Find(x), rY = Find(y);
        //they have same root, already in same component
        if (rX == rY)
            return 0;// does not affect the components
        if (rank[rX] > rank[rY])
            swap(rX, rY);
        root[rX] = rY;
        if (rank[rX] == rank[rY])
            rank[rY]++;
        return 1;// connect 2 disjoint components
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

