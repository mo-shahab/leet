class Solution {
public:

    unordered_map<char, string> keyboard = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"},
    };

    vector<string> letterCombinations(string digits) 
    {
        vector<string> result;
        string substr;

        if(digits.length() == 0) return result;
        dfs(digits, result, substr, 0);
        return result;
    }

    void dfs(string& digits, vector<string>& result, string& substr, int start)
    {
        if(start == digits.length())
        {
            result.push_back(substr);
            return;
        }

        for(char c: keyboard[digits[start]])
        {
            substr.push_back(c);
            dfs(digits, result, substr, start + 1);
            substr.pop_back();
        }
    }
};