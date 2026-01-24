class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> results;
        if(n <= 0) return {{}};

        vector<string> board(n , string(n, '.'));
        dfs(board, results, 0); // pass the rvalue for the row;

        return results;
    }

    void dfs(vector<string>& board, vector<vector<string>>& results, int row)
    {
        if(row == board.size()){
            results.push_back(board);
            return;
        }
        
        for(int i = 0; i < board.size(); i++)
        {
            if(isValid(board, row, i)) {
                board[row][i] = 'Q'; // act upon the decision on that thing 
                dfs(board, results, row + 1); // then do the same for the next row;
                board[row][i] = '.';
            }
        }
    }

    bool isValid(vector<string>& board, int row, int col) {
        // checks for rows if any rows at the given col has queen
        for(int i = row; i >= 0; i--) {
            if(board[i][col] == 'Q') return false;
        }

        // upper left diagonal check
        for(int i= row, j = col; i >= 0 && j >= 0; i--, j--)
        {
            if(board[i][j]== 'Q') return false; 
        }

        for(int i = row, j = col; i >= 0 && j < board.size(); i--, j++)
        {
            if(board[i][j] == 'Q') return false;
        }


        return true;
    }
};