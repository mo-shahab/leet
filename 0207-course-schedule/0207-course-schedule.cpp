// use kahns algorithm in here
class Solution {
public:
    typedef vector<vector<int>> graph;

    graph buildGraph(int n, vector<vector<int>>& pre) {
        graph g(n);

        for(auto& p : pre) {
            // Edge goes from Prereq (p[1]) to Course (p[0])
            g[p[1]].push_back(p[0]); 
        }
        return g;
    }

    vector<int> computeIndegrees(int n, vector<vector<int>>& pre) {
        vector<int> degrees(n, 0);
        // consider [i, j];
        // the edge is coming from j-> i , so its inning the i,
        // so p[0] is the proper thing in here 
        for(auto& p : pre) {
            degrees[p[0]]++; // Course p[0] depends on p[1]
        }
        return degrees;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        graph g = buildGraph(numCourses, prerequisites);

        vector<int> degrees = computeIndegrees(numCourses, prerequisites);
        int count = 0;

        queue<int> q;
        // take in all the nodes that have indegree as 0
        for (int i = 0; i < numCourses; i++) {
            if (degrees[i] == 0) {
                q.push(i);
            }
        }

        while(!q.empty()) {
            auto curr = q.front();
            count++;
            q.pop();

            for(auto next: g[curr]) {
                degrees[next]--;

                if(degrees[next] == 0) q.push(next);
            }
        }
        return count == numCourses;
    }
};