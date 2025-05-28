class Solution {
public:
    typedef vector<vector<int>> graph;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        graph g = buildGraph(numCourses, prerequisites);
        vector<int> degrees = computeIndegrees(g);

        for(int i = 0; i < numCourses; i++)
        {
            int j = 0; 
            // this is like checking if any of the degrees is not 0, at any given time
            for(; j < numCourses; j++)    
            {
                if(!degrees[j]) break;
            } 
            if(j == numCourses) return false;

            degrees[j]--;

            for(int v: g[j]) degrees[v]--;
        }

        return true;
    }

    graph buildGraph(int numCourses, vector<vector<int>>& pre)
    {
        graph g(numCourses);

        for(auto& p: pre)
        {
            g[p[1]].push_back(p[0]);
        }

        return g;
    }

    vector<int> computeIndegrees(graph& g)
    {
        vector<int> degrees(g.size(), 0);

        for(auto adj: g)
        {
            for(int v: adj)
            {
                degrees[v]++;
            }
        }

        return degrees;
    }
};