int dr[]{1,-1,0, 0};       
int dc[]{0, 0,1,-1,};
class Solution {
public:
    int n, m;
    vector<vector<char>> _board;
    string _word;

    bool isValid(int row, int col)
    {
        if (row < 0 || row >= n) return false;
        if (col < 0 || col >= m) return false;
        return true;
    }

    bool dfs(
        int row, 
        int col, 
        int ptr
    )
    {
        if(ptr == _word.size()) return true;

        if(
            !isValid(row, col) || 
            _board[row][col] == '0' || 
            _word[ptr] != _board[row][col]
        ) 
            return false;

        char temp = _board[row][col];
        _board[row][col] = '0';

        for (int i = 0; i < 4; ++i) 
        {
            if(dfs(row + dr[i], col + dc[i], ptr+1)) return true;
                
        }

        _board[row][col] = temp;
        return false;

    }


    bool exist(vector<vector<char>>& board, string word) 
    {
        n = board.size(), m = board[0].size();
        _board = board;
        _word = word;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++){
                // here i is the row, j is the col and 
                // 0 is the pointer for the word, which means 
                // first letter of the word
                if (dfs(i, j, 0)) return true;
            }
        }

        return false;
    }
};