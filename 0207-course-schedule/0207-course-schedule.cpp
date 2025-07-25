class Solution {
public:
    typedef vector<vector<int>> graph;

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        graph g = build_graph(prerequisites, numCourses);

        vector<bool> done(numCourses, false), todo(numCourses, false);

        for(int i = 0; i < numCourses; i++){
            if(!done[i] && !dfs(g, done, todo, i)){
                return false;
            }
        }

        return true;
    }

    graph build_graph(graph& pre, int num){
        graph g(num); 

        for(auto& p: pre){
            g[p[0]].push_back(p[1]);
        }

        return g;
    }

    bool dfs(graph& g, vector<bool>& done, vector<bool>& todo, int node){
        if(todo[node]){
            return false;
        }

        if(done[node]){
            return true;
        }

        todo[node] = done[node] = true;

        for(auto& v: g[node]){
            if(!dfs(g, done, todo, v)){
                return false;
            }
        }

        todo[node] = false;

        return true;
    }


};