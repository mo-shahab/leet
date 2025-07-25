class Solution {
public:
    int dRow[4] = {0, 0, -1, 1};
    int dCol[4] = {1, -1, 0, 0};
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int countFreshOranges = 0;
        int eta = 0;

        queue<pair<int, int>> q;

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == 1) countFreshOranges++;

                if(grid[i][j] == 2) q.push({i, j});
            }
        }

        while(!q.empty() && countFreshOranges != 0){
            int qsize = q.size();

            for(int i = 0; i < qsize; i++){
                auto curr = q.front();
                int row = curr.first;
                int col = curr.second;

                q.pop();

                for(int i = 0; i < 4; i++){
                    int adjx = row + dRow[i];
                    int adjy = col + dCol[i];

                    if(adjx >= 0 && adjy >= 0 && adjx < rows && adjy < cols && grid[adjx][adjy]  == 1) {
                        countFreshOranges--;
                        grid[adjx][adjy] = 2;
                        q.push({adjx, adjy});
                    }
                }
            }

            eta++;
        }

        return countFreshOranges == 0 ? eta: -1;
    }
};