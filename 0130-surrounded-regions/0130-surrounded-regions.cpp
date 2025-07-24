class Solution {
public:
    int dRow[4] = {-1, 0, 0, 1};
    int dCol[4] = {0, -1, 1, 0};
    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();

        vector<vector<bool>> vis(rows, vector(cols, false));

        // phase 1 marking all the unsurrounded regions 
        // as 'T'
        queue<pair<int, int>> q;
        for(int i = 0; i < rows; i++){
            if(board[i][0] == 'O'){
                q.push({i, 0});
                board[i][0] = 'T';
                vis[i][0] = true;
            }
            if(board[i][cols-1] == 'O'){
                q.push({i, cols-1});
                board[i][cols-1] = 'T';
                vis[i][cols-1] = true;
            }
        }

        for(int i = 0; i < cols; i++){
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

        while(!q.empty()){
            pair<int, int> curr = q.front();

            int row =  curr.first;
            int col = curr.second;

            q.pop();

            for(int i = 0; i < 4; i++){
                int adjx = row + dRow[i];
                int adjy = col + dCol[i];

                if(adjx >= 0 && adjy >= 0 && adjx < rows && adjy < cols && !vis[adjx][adjy]){
                    if(board[adjx][adjy] == 'O'){
                        board[adjx][adjy] = 'T';
                        vis[adjx][adjy] = true;
                        q.push({adjx, adjy});
                    }
                }
            }
        }

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++){
                if(board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(board[i][j] == 'T'){
                    board[i][j] = 'O';
                }
            }
        }

    }
};