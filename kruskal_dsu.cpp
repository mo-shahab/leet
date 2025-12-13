class Solution {
public:
    struct Edge {
        int u, v, weight;
        Edge(int _u, int _v, int _w) : u(_u), v(_v), weight(_w) {}
    };

    // Disjoint Set Union (Union-Find)
    class DSU {
    public:
        vector<int> parent, rank;

        DSU(int n) {
            parent.resize(n);
            rank.resize(n, 0);
            for (int i = 0; i < n; i++)
                parent[i] = i;
        }

        int find(int x) {
            if (parent[x] != x)
                parent[x] = find(parent[x]);  // path compression
            return parent[x];
        }

        bool unite(int x, int y) {
            int rootX = find(x);
            int rootY = find(y);
            if (rootX == rootY)
                return false;  // already in same set

            // union by rank
            if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
            return true;
        }
    };

    // Function to return total cost of MST
    int kruskalMST(int n, vector<vector<int>>& edgesInput) {
        vector<Edge> edges;
        for (auto& e : edgesInput)
            edges.emplace_back(e[0], e[1], e[2]);

        // Sort edges by weight
        sort(edges.begin(), edges.end(), [](Edge& a, Edge& b) {
            return a.weight < b.weight;
        });

        DSU dsu(n);
        int mstWeight = 0;
        vector<pair<int, int>> mstEdges;

        for (auto& e : edges) {
            if (dsu.unite(e.u, e.v)) {
                mstWeight += e.weight;
                mstEdges.emplace_back(e.u, e.v);  // this edge is in MST
            }
        }

        // Optional: check if all nodes are connected (MST must have n - 1 edges)
        if (mstEdges.size() != n - 1)
            return -1;  // MST not possible (graph not connected)

        return mstWeight;
    }
};
