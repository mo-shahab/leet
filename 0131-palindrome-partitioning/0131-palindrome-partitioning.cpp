class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> subs; // result
        vector<string> sub; // a single subset

        backtrack(s, subs, sub, 0);

        return subs;
    }

    void backtrack(string& s, vector<vector<string>>& subs, vector<string>& sub,  int i)
    {
        if(i == s.size())
        {
            subs.push_back(sub);
            return;
        }
        for(int j = i; j < s.size(); j++)
        {
            if(isPalindrome(s, i, j))
            {
                sub.push_back(s.substr(i, j-i+1));
                backtrack(s, subs, sub, j + 1);
                sub.pop_back();
            }
        }
    }

    bool isPalindrome(string& s, int left, int right)
    {
        while(left < right)
        {
            if(s[left++] != s[right--]) return false;
        }

        return true;
    }


};