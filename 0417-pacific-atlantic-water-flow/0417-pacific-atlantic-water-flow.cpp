class Solution {
public:
    int dRow[4] = {0, -1, 0, 1};
    int dCol[4] = {-1, 0, 1, 0};

    void bfs(vector<vector<int>> &height, vector<vector<int>> &vis, int rows, int cols, queue<pair<int, int>> &q)
    {
        while (!q.empty()){
            auto curr = q.front();
            int row = curr.first;
            int col = curr.second;

            q.pop();

            vis[row][col] = 1;

            for(int i = 0; i < 4; i++){
                int adjx = row + dRow[i];
                int adjy = col + dCol[i];

                if(adjx >= 0 && adjy >= 0 && adjx < rows && adjy < cols) {
                    if(height[adjx][adjy] >= height[row][col] && !vis[adjx][adjy]){
                        q.push({adjx, adjy});
                        vis[adjx][adjy] = 1;
                    }
                }
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> result;    

        int rows = heights.size();
        int cols = heights[0].size();

        vector<vector<int>> pacific(rows, vector<int>(cols, 0));
        vector<vector<int>> atlantic(rows, vector<int>(cols, 0));


        queue<pair<int, int>> q;
        for(int i = 0; i < cols; i++) q.push({0, i});
        for(int i = 0; i < rows; i++) q.push({i, 0});
        bfs(heights, pacific, rows, cols, q);

        queue<pair<int, int>> q1;
        for(int i = 0; i < cols; i++) q1.push({rows-1, i});
        for(int i = 0; i < rows; i++) q1.push({i, cols-1});
        bfs(heights, atlantic, rows, cols, q1);

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(pacific[i][j] == atlantic[i][j] && pacific[i][j] == 1) {
                    result.push_back({i, j});
                }
            }
        }

        return result;
    }
};