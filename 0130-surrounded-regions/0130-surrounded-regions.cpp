class Solution {
public:
    int dRow[4] = {-1, 0, 0, 1};
    int dCol[4] = {0, -1, 1, 0};
    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();

        // phase 1 marking all the unsurrounded regions 
        // as 'T'

        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        queue<pair<int, int>> q;
        for(int i = 0; i < rows; i++) {
            if(board[i][0] == 'O' && !visited[i][0]) {
                q.push({i, 0});
                visited[i][0] = true;
                board[i][0] = 'T';
            }
            if(board[i][cols - 1] == 'O' && !visited[i][cols - 1]) {
                q.push({i, cols - 1});
                visited[i][cols - 1] = true;
                board[i][cols - 1] = 'T';
            }
        }
        
        for(int j = 0; j < cols; j++) {
            if(board[0][j] == 'O' && !visited[0][j]) {
                q.push({0, j});
                visited[0][j] = true;
                board[0][j] = 'T';
            }
            if(board[rows - 1][j] == 'O' && !visited[rows - 1][j]) {
                q.push({rows - 1, j});
                visited[rows - 1][j] = true;
                board[rows - 1][j] = 'T';
            }
        }

        
        // marking all the unsurrounded regions with 'T'
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

                if(adjx >= 0 && adjy >= 0 && adjx < rows && adjy < cols && !visited[adjx][adjy] && board[adjx][adjy] == 'O')
                {
                    board[adjx][adjy] = 'T';
                    q.push({adjx, adjy});
                    visited[adjx][adjy] = true;
                }
            }
        }

        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                if(board[i][j] == 'O')
                {
                    board[i][j] = 'X';
                }
            }
        }

        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                if(board[i][j] == 'T')
                {
                    board[i][j] = 'O';
                }
            }
        }
    }
};