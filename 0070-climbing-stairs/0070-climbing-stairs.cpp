class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1);

        dp[0] = 1; // first step
        dp[1] = 2; // second step

        for(int i = 2; i < n ; i++) {
            dp[i] = dp[i-1] + dp[i-2]; // its simply how many ways from one prev step and two prev steps
        }

        return dp[n - 1];
    }
};