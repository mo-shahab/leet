class Solution {
public:
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {1, -1, 0, 0};

    typedef vector<vector<int>> graph;
    typedef vector<vector<bool>> visited;

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int res = 0; // keeps track of the maximum of the area of island and such, 

        visited vis(rows, vector<bool>(cols, false));

        for(int i =0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(!vis[i][j] && grid[i][j] == 1){
                    res = max(res, bfs(grid, vis, i, j, rows, cols));
                }
            }
        }

        return res;

    }

    int bfs(graph& grid, visited& vis, int row, int col, int& rows, int& cols) {
        queue<pair<int, int>> q;
        int count = 1; // this will keep the count of the nodes that it is visiting and such

        q.push({row, col});
        vis[row][col] = true;

        while(!q.empty()) {
            auto curr = q.front();

            int curr_row = curr.first;
            int curr_col = curr.second;

            q.pop();

            for(int i = 0; i < 4; i++) {
                int adjx = curr_row + dx[i];
                int adjy = curr_col + dy[i];

                if(
                    adjx >= 0 &&
                    adjy >= 0 &&
                    adjx < rows &&
                    adjy < cols && 
                    !vis[adjx][adjy] && 
                    grid[adjx][adjy] == 1
                ) {
                    q.push({adjx, adjy});
                    vis[adjx][adjy] = true;
                    count++ ;
                }
            }
        }

        return count;
    }
};