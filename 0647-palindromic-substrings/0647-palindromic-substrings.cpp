class Solution {
public:
    int countSubstrings(string s) {
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        int count = 0;


        for(int i = s.size() - 1; i >= 0; i--)
        {
            for(int j = 0; j < s.size(); j++)
            {
                if(i == j) dp[i][j] = true;

                else if(i + 1 == j) dp[i][j] = s[i] == s[j] ? true : false;

                else {
                    dp[i][j] = (s[i] == s[j] && dp[i+1][j-1] );
                }
            }
        }

        for(int i = 0; i < s.size(); i++)
        {
            for(int j = 0; j < s.size(); j++)
            {
                if(dp[i][j]) count++;
            }
        }

        return count;
    }
};