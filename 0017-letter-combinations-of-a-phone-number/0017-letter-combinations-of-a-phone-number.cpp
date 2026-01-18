class Solution {
public:

    unordered_map<char, string> hashmap = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"},
    };

    vector<string> letterCombinations(string digits) {
        vector<string> subs;        

        string curr = "";

        backtrack(subs, curr, digits, 0);
        return subs;
    }

    void backtrack(vector<string>& subs, string current, string digits, int i )
    {
        if(current.length() == digits.length()) {
            subs.push_back(current);
            return;
        }

        for(char c: hashmap[digits[i]]) {
            current.push_back(c);
            backtrack(subs, current, digits, i+1);
            current.pop_back();
        }
    }
};