class Solution {
public:
    int dRow[4] = {0, -1, 0, 1};
    int dCol[4] = {-1, 0, 1, 0};

    void bfs(vector<vector<int>>& h, queue<pair<int, int>>& q, vector<vector<int>>& vis)
    {
        int rows = h.size();
        int cols = h[0].size();

        while(!q.empty())
        {
            auto curr = q.front();
            int row = curr.first;
            int col = curr.second;

            q.pop();
            vis[row][col] = 1;

            for(int i{}; i < 4; i++)
            {
                int adjx = row + dRow[i];
                int adjy = col + dCol[i];

                if(adjx >= 0 && adjy >= 0 && adjx < rows && adjy < cols)
                {
                    if(h[adjx][adjy] >= h[row][col] && vis[adjx][adjy] == 0)
                    {
                        q.push({adjx, adjy});
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

        queue<pair<int, int>> q1;
        for(int i{}; i < rows; i++) q1.push({i, 0});
        for(int j{}; j < cols; j++) q1.push({0, j});
        bfs(heights, q1, pacific);

        queue<pair<int, int>> q2;
        for(int i{}; i < rows; i++) q2.push({i, cols - 1});
        for(int j{}; j < cols; j++) q2.push({rows - 1, j});
        bfs(heights, q2, atlantic);

        for(int i{}; i < rows; i++)
        {
            for(int j{}; j < cols; j++)
            {
                if(pacific[i][j] == 1 && atlantic[i][j] == 1) result.push_back({i, j});
            }
        }

        return result;
    }
};