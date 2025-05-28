class Solution {
public:
    typedef vector<vector<int>> graph;
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        graph g = buildGraph(numCourses, prerequisites);
        vector<int> degrees = indegrees(g);

        vector<int> result;
        vector<bool> visited(numCourses, false);

        for(int i = 0; i < g.size(); i++)
        {
            int j = 0;
            for(; j < degrees.size(); j++)
            {
                if(degrees[j] == 0 && !visited[j])
                {
                    degrees[j]--;
                    result.push_back(j);
                    visited[j] = true;
                    for(int& v: g[j]) degrees[v]--;
                }
            }
        }

        return result.size() == numCourses ? result : vector<int>();
    }

    graph buildGraph(int num, vector<vector<int>>& pre)
    {
        graph g(num);
        for(auto& p: pre)
        {
            g[p[1]].push_back(p[0]);
        }
        return g;
    }

    vector<int> indegrees(graph& g)
    {
        vector<int> degrees(g.size(), 0);
        for(auto& v: g)
        {
            for(int i = 0; i < v.size(); i++)
            {
                degrees[v[i]]++;
            }
        }
        return degrees; 
    }
};