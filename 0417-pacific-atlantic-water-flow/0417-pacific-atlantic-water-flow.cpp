class Solution {
public:
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {1, -1, 0, 0};

    typedef vector<vector<int>> graph;

    void bfs(graph& grid, graph& vis, queue<pair<int, int>>& q,  int row, int col, int& rows, int&cols) {
        while(!q.empty()) { 
            auto curr = q.front();
            
            int curr_row = curr.first;
            int curr_col = curr.second;

            vis[curr_row][curr_col] = 1;

            q.pop();

            for(int i = 0; i < 4; i++) {
                int adjx = curr_row + dx[i];
                int adjy = curr_col + dy[i];

                if(
                    adjx >= 0 &&
                    adjy >= 0 && 
                    adjx < rows && 
                    adjy < cols && 
                    grid[adjx][adjy] >= grid[curr_row][curr_col] && 
                    vis[adjx][adjy] != 1
                ) { 
                    q.push({adjx, adjy});
                }
            }

        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();

        // queue used to run multi source bfs on all the edge nodes
        // that can reach the pacific;
        queue<pair<int, int>> q1;

        // same but will check for 
        queue<pair<int, int>> q2;

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++){
                if(i == 0 || j == 0) q1.push({i, j});
                if(i == rows-1 || j == cols-1) q2.push({i, j});
            }
        }

        // all the vertices that can reach to pacific
        graph pacific(rows, vector<int>(cols, 0));
        bfs(heights, pacific, q1, 0, 0, rows, cols);

        // all the vertices that can reach to atlantic
        graph atlantic(rows, vector<int>(cols, 0));
        bfs(heights, atlantic, q2, 0, 0, rows, cols);
        
        vector<vector<int>> result; 

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(pacific[i][j] && atlantic[i][j]) {
                    result.push_back({i, j});
                }
            }
        }

        return result;
    }
};