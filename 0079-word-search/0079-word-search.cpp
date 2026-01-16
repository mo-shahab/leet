// this is dfs and backtracking type shi
class Solution {
public:

    int dy[4] = {1, -1, 0, 0};
    int dx[4] = {0, 0, 1, -1};

    bool exist(vector<vector<char>>& board, string word) {

        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++)
            {
                if(board[i][j] == word[0]) {
                    if(backtrack(board, word, i, j, 0))
                    {
                        return true;
                    }
                }
            }
        }

        return false;

    }

// w_count is the number of the letter of the word that we are trying to match and stuff
    bool backtrack(vector<vector<char>>& board, string word, int row, int col, int w_count)
    {
        if(board[row][col] != word[w_count])
        {
            return false;
        }
        if(w_count == word.size() - 1) return true;

        char temp = board[row][col];
        board[row][col] = '.';

        for(int i = 0; i < 4; i++)
        {
            int adjx = row + dx[i];
            int adjy = col + dy[i];

            if(
                adjx >= 0 &&
                adjy >= 0 &&
                adjx < board.size()  &&
                adjy < board[0].size()  &&
                board[adjx][adjy] != '.' &&
                board[adjx][adjy] == word[w_count + 1]
            )
            {
                if(backtrack(board, word, adjx, adjy, w_count + 1)) return true; // catch the thing and stuff 
            }
        }

        board[row][col] = temp;
        return false;
    }
};