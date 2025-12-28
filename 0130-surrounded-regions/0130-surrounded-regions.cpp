class Solution {
public:
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {1, -1, 0, 0};

    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();

        queue<pair<int, int>> q;

        vector<vector<bool>> vis(rows, vector<bool>(cols, false));

        // marking all the Os at the border as 'T'
        for(int i = 0; i < rows; i++) {
            if(board[i][0] == 'O') {
                q.push({i, 0});
                board[i][0] = 'T';
                vis[i][0] = true;
            }
            if(board[i][cols-1] == 'O') {
                q.push({i, cols-1}) ;
                board[i][cols-1] = 'T';
                vis[i][cols-1] = true;
            }
        }

        for(int i = 0; i < cols; i++) {
            if(board[0][i] == 'O'){
                q.push({0, i});
                board[0][i] =  'T';
                vis[0][i] = true;
            }
            if(board[rows-1][i] == 'O'){
                q.push({rows-1, i});
                board[rows-1][i] = 'T';
                vis[rows-1][i] = true;
            }    
        }

        while(!q.empty()) {
            auto curr = q.front();

            int curr_row = curr.first;
            int curr_col = curr.second;

            q.pop();

            // these are all the Os which are connected to the border and stuff
            for(int j = 0; j < 4; j++ ) {
                int adjx = dx[j] + curr_row;
                int adjy = dy[j] + curr_col;

                if(
                    adjx >= 0 &&
                    adjy >= 0 &&
                    adjx < rows && 
                    adjy < cols && 
                    !vis[adjx][adjy] &&
                    board[adjx][adjy] == 'O'
                ) {
                    q.push({adjx, adjy});
                    board[adjx][adjy] = 'T';
                    vis[adjx][adjy] = true;
                }
            }
        }

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j< cols;j++) {
                if(board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(board[i][j] == 'T') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};