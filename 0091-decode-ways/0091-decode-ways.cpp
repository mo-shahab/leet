class Solution {
public:
    int numDecodings(string s) {
        if(s[0] == '0') return 0;

        vector<int> dp(s.length() + 1);

        dp[0] = 1;
        dp[1] = 1;

        for(int i = 2; i <= s.length(); i++)
        {
            int one = s[i-1] - '0'; // previous character
            int two = stoi(s.substr(i-2, 2)); // previous two characters

            if(1 <= one && one <= 9) dp[i] += dp[i - 1];
            if(10 <= two && two <= 26) dp[i] += dp[i-2];
        }

        return dp[s.length() ];
    }
};