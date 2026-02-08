class Solution {
public:
    int numDecodings(string s) {
        if(s[0] == '0') {
            return 0;
        }

        int n =  s.length();

        vector<int> dp(n + 1, 0);
        dp[0] = dp[1] = 1; // one way to decode for 0 characters and 1 character

        for(int i = 2; i <= n; i++) {
            int one = s[i-1] - '0'; // previous character
            int two = stoi(s.substr(i-2, 2)); // previous two characters

            if(1 <= one && one <= 9) {
                dp[i] += dp[i-1];
            }

            if(10 <= two && two < 27) {
                dp[i] += dp[i-2];
            }
        }

        return dp[n];
    }
};