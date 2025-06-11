class Solution {
public:
    vector<string> generateParenthesis(int n) {
        
        vector<string> result;
        string current = "";

        backtrack(result, current, n, 0, 0);
        return result;
    }

    void backtrack(vector<string> &result, string &current, int n, int c_open, int c_close){
        if(c_close == c_open && c_open == n){
            result.push_back(current);
            return;
        }

        if(c_open < n){
            current += "(";
            backtrack(result, current, n, c_open + 1, c_close);
            current.pop_back();
        }

        if(c_close < c_open){
            current += ")";
            backtrack(result, current, n, c_open, c_close + 1);
            current.pop_back();
        }
    }
};