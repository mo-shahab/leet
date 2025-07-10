class Solution {
public:
    int dRow[4] = {0, -1, 0, 1};
    int dCol[4] = {-1, 0, 1, 0};

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int max_area = 0;

        vector<vector<bool>> vis(rows, vector<bool>(cols, false));

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (grid[row][col] == 1 && !vis[row][col]) {
                    int area = bfs(grid, vis, row, col, rows, cols);
                    max_area = max(max_area, area);
                }
            }
        }
        return max_area;
    }

    int bfs(vector<vector<int>>& grid, vector<vector<bool>>& vis, int row, int col, int rows, int cols) {
        queue<pair<int, int>> q;
        q.push({row, col});
        vis[row][col] = true;
        int area = 1; // Count the starting cell

        while (!q.empty()) {
            auto curr = q.front();
            q.pop();

            int row = curr.first;
            int col = curr.second;

            for (int i = 0; i < 4; i++) {
                int adjx = row + dRow[i];
                int adjy = col + dCol[i];

                // Fix bounds check: adjx < rows, adjy < cols
                if (adjx >= 0 && adjy >= 0 && adjx < rows && adjy < cols) {
                    if (!vis[adjx][adjy] && grid[adjx][adjy] == 1) {
                        vis[adjx][adjy] = true;
                        q.push({adjx, adjy});
                        area++; // Increment for each new land cell
                    }
                }
            }
        }

        return area;
    }
};