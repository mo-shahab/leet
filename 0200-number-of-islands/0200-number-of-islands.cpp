class Solution {
public:
    int dRow[4] = {0, -1, 0, 1};
    int dCol[4] = {-1, 0, 1, 0};
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int count = 0;

        vector<vector<bool>> vis(rows, vector<bool>(cols, false));

        // lets write a for loop properly 
        for(int row = 0; row < rows; row++){
            for(int col = 0; col < cols; col++){
                if(
                    grid[row][col] == '1' && !vis[row][col]
                ){
                    bfs(grid, row, col, rows, cols, vis); 
                    count++;
                }
            }
        }

        return count;
    }

    void bfs(vector<vector<char>> &grid, int &row, int &col, int &rows, int &cols, vector<vector<bool>> &vis) {

        queue<pair<int, int>> q;
        q.push({row, col});
        vis[row][col] = true;

        while(!q.empty()){
            auto& curr = q.front();

            int row = curr.first;
            int col = curr.second;

            q.pop();

            vis[row][col] = true;

            for(int i = 0; i < 4; i++){
                int adjx = row + dRow[i];
                int adjy = col + dCol[i];

                if(
                    adjx >= 0 && 
                    adjy >= 0 && 
                    adjx < rows && 
                    adjy < cols && 
                    !vis[adjx][adjy] && 
                    grid[adjx][adjy] == '1'
                    ){
                    q.push({adjx, adjy});
                    vis[adjx][adjy] = true;
                }
            }
        }
    }
};