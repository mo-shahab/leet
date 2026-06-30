class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        
        // Change from int to unsigned long long to prevent overflow during additions
        vector<vector<unsigned long long>> dp(n + 1, vector<unsigned long long>(amount + 1, 0));

        for (int c = 0; c <= n; c++) dp[c][0] = 1;

        for (int c = 1; c <= n; c++) {
            for (int i = 1; i <= amount; i++) {
                dp[c][i] = dp[c - 1][i]; 
                
                if (i - coins[c - 1] >= 0) {
                    dp[c][i] += dp[c][i - coins[c - 1]]; 
                }
            }
        }

        // The method return type is still int because LeetCode guarantees the final 
        // answer fits in a standard integer, but intermediate states overflow.
        return dp[n][amount];
    }
};