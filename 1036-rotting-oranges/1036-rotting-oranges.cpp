class Solution {
public:
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {1, -1, 0, 0};

    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        int eta = 0; // this is the answer;
        int freshOranges;

        queue<pair<int, int>> q;

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++) {
                if(grid[i][j] == 2) q.push({i, j});
                if(grid[i][j] == 1) freshOranges++;
            }
        }

        while(!q.empty() && freshOranges > 0) {
            int size = q.size();

            for(int i = 0; i < size; i++) {
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
                        grid[adjx][adjy] == 1
                    ) {
                        freshOranges--;
                        grid[adjx][adjy] = 2; // make them rotten
                        q.push({adjx, adjy});
                    }
                }
            }
            eta++;
        }


        return freshOranges > 0 ? -1: eta;
    }
};