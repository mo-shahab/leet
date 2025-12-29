class Solution {
public:
    typedef vector<vector<int>> graph;

    graph buildGraph(int n, vector<vector<int>>& pre) {
        graph g(n); 
        for(auto p: pre) {
            g[p[1]].push_back(p[0]);
        }
        return g;
    }

    vector<int> computeIndegrees(int n, vector<vector<int>>& pre) {
        vector<int> degrees(n, 0);
        for(auto p: pre) {
            degrees[p[0]]++;
        }
        return degrees;
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        graph g = buildGraph(numCourses, prerequisites);
        vector<int> degrees = computeIndegrees(numCourses, prerequisites);
        vector<int> result;
        vector<int> empty = {};

        queue<int> q;

        // we will start the bfs from where the indegree is 0
        for(int i = 0; i < numCourses; i++) {
            if(degrees[i] == 0) q.push(i);
        }

        while(!q.empty()) {
            auto curr = q.front();

            result.push_back(curr);
            q.pop();

            for(int v: g[curr]) {
                degrees[v]--;

                if(degrees[v] == 0) q.push(v);
            }
        }

        return result.size() == numCourses ? result : empty;
    }
};