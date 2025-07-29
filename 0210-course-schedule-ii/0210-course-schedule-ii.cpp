class Solution {
public:
    typedef vector<vector<int>> graph;

    // Corrected buildGraph
    graph buildGraph(int num, vector<vector<int>>& pre) {
        graph g(num); // Initialize with num empty vectors
        for(const auto& p : pre) {
            // p[1] is prerequisite for p[0], so edge p[1] -> p[0]
            g[p[1]].push_back(p[0]);
        }
        return g;
    }

    // Corrected indegrees
    vector<int> indegrees(int numCourses, const graph& g) {
        vector<int> degrees(numCourses, 0); // Initialize all to 0
        for(int u = 0; u < g.size(); ++u) { // Iterate through each node
            for(int v : g[u]) { // For each neighbor v of u (edge u -> v)
                degrees[v]++; // Increment in-degree of v
            }
        }
        return degrees;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        graph g = buildGraph(numCourses, prerequisites);
        vector<int> inDegree = indegrees(numCourses, g);
        vector<int> result;
        queue<int> q;

        // 1. Initialize queue with all nodes having an in-degree of 0
        for (int i = 0; i < numCourses; ++i) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        // 2. Process nodes from the queue
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            result.push_back(u);

            // For each neighbor v of u
            for (int v : g[u]) {
                inDegree[v]--; // Decrement in-degree of neighbor
                if (inDegree[v] == 0) { // If neighbor's in-degree becomes 0, enqueue it
                    q.push(v);
                }
            }
        }

        // 3. Check for cycles
        // If the size of the result list is not equal to numCourses, a cycle exists
        if (result.size() == numCourses) {
            return result;
        } else {
            return {}; // Return empty vector indicating a cycle
        }
    }
};