class Solution {
public:
    int dRow[4] = {0, -1, 0, 1};
    int dCol[4] = {-1, 0, 1, 0};

    int numIslands(vector<vector<char>>& grid) 
    {
        if(grid.empty()) return 0;

        int rows = grid.size();
        int cols = grid[0].size();
        
        vector<vector<bool>> vis(rows, vector<bool>(cols, false));
        int islands = 0;

        for(int row = 0; row < rows; row++)
        {
            for(int col = 0; col < cols; col++)
            {
                if(grid[row][col] == '1' && (!vis[row][col]))
                {
                    bfs(grid, vis, row, col, rows, cols);
                    islands++;
                }
            }
        }
        return islands;
    }
    
    void bfs(vector<vector<char>>& grid, vector<vector<bool>>& vis, int row, int col, int rows, int cols)
    {
        queue<pair<int, int>> q;
        q.push({row, col});
        vis[row][col] = true;

        while(!q.empty())
        {
            pair<int, int> curr = q.front();
            int row = curr.first;
            int col = curr.second;

            q.pop();

            for(int i = 0; i < 4; i++)
            {
                int adjx = row + dRow[i];
                int adjy = col + dCol[i];
                
                if(adjx >= 0 && adjx < rows && adjy >= 0 && adjy < cols)
                {
                    if(!vis[adjx][adjy] && grid[adjx][adjy] == '1')
                    {
                        q.push({adjx, adjy});
                        vis[adjx][adjy] = true;
                    }
                }
            }
        }
    }
};