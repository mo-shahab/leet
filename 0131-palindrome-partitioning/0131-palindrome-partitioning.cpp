class Solution {
public:
    vector<vector<string>> partition(string s) 
    {
        vector<vector<string>> result;
        vector<string> subset;

        dfs(s, result, subset, 0);
        return result;
    }

    void dfs(string& s, vector<vector<string>>& result, vector<string>& subset, int start)
    {
        if(start == s.length()){
            result.push_back(subset);
        }

        for(int i = start + 1; i <= s.length(); i++)
        {
            if(isPalindrome(s, start , i - 1))     
            {
                subset.push_back(s.substr(start, i - start));
                dfs(s, result, subset, i);
                subset.pop_back();
            }
        }
    }

    bool isPalindrome(const string& s, int left, int right){
        while(left < right)
        {
            if(s[left++] != s[right--])
            {
                return false;
            }
        }

        return true;
    }

};