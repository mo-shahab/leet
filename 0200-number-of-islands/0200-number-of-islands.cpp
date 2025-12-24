class Solution {
public:
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {1, -1, 0, 0};

    typedef vector<vector<char>> graph;
    typedef vector<vector<bool>> visited;

    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int count = 0;

        vector<vector<bool>> vis(rows, vector<bool> (cols, false));

        for(int i = 0; i< rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(grid[i][j]  == '1' && !vis[i][j]) {
                    bfs(grid, vis, i, j, rows, cols);
                    count++;
                }
            }
        }

        return count;
    }

    void bfs(graph& grid, visited& vis, int& row, int& col, int& rows, int& cols) {
        queue<pair<int, int>> q;
        q.push({row, col});

        vis[row][col] = true;

        while(!q.empty()) {
            auto curr = q.front();

            int curr_row = curr.first;
            int curr_col = curr.second;

            q.pop();
            vis[curr_row][curr_col]= true;

            for(int i = 0; i < 4; i++) {
                int adjx = curr_row + dx[i];
                int adjy = curr_col + dy[i];

                if(adjx >= 0 && adjy >= 0 && adjx < rows && adjy < cols && !vis[adjx][adjy] && grid[adjx][adjy] == '1') {
                    q.push({adjx, adjy});
                    vis[adjx][adjy] = true;
                }
            }
        }
    }
};