class Solution {
public:
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {1, -1, 0, 0};

    typedef vector<vector<bool>> visited;
    typedef vector<vector<char>> graph; 

    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int count = 0;

        visited vis(rows, vector<bool>(cols, false));

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(!vis[i][j] && grid[i][j] == '1') {
                    dfs(grid, vis, i, j, rows, cols);
                    count++;
                }
            }
        }

        return count;

    }

    void dfs(graph& grid, visited& vis, int row, int col, int& rows, int&cols) {
        vis[row][col] = true;

        for(int i = 0; i < 4; i++) {
            int adjx = row + dx[i];
            int adjy = col + dy[i];

            if(
                adjx >= 0 &&
                adjy >= 0 &&
                adjx < rows && 
                adjy < cols && 
                !vis[adjx][adjy] && 
                grid[adjx][adjy] == '1'
            ) {
                vis[adjx][adjy] = true;
                dfs(grid, vis, adjx, adjy, rows, cols);
            }
        }
    }
};