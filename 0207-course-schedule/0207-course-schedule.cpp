class Solution {
public:
    typedef vector<vector<int>> graph;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        graph g = buildGraph(numCourses, prerequisites);
        vector<bool> todo(numCourses, false), done(numCourses, false);
        
        for(int i = 0; i < numCourses; i++)
        {
            if(!done[i] && !dfs(g, todo, done, i))
            {
                return false;
            }
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

    bool dfs(graph& g,  vector<bool>& todo, vector<bool>& done, int node)
    {
        if(todo[node])
        {
            return false;
        }

        if(done[node])
        {
            return true;
        }

        todo[node] = done[node] = true;

        for(int v: g[node])
        {
            if(!dfs(g, todo, done, v))
            {
                return false;
            }
        }
        todo[node] = false;
        return true;
    }
};