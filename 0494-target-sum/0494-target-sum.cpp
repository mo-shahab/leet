class Solution {
public:
    int findTargetSumWays(std::vector<int>& nums, int target) {
        // Calculate total sum of the array
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }
        
        // Edge cases: target is unreachable if (target + sum) is negative 
        // or if it's odd (cannot be divided into a whole subset)
        if (target + sum < 0 || (target + sum) % 2 != 0) {
            return 0;
        }
        
        int subsetTarget = (target + sum) / 2;
        int n = nums.size();
        
        // Create a 2D DP table initialized to 0
        // Rows: 0 to n (elements considered)
        // Cols: 0 to subsetTarget (sums we want to reach)
        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(subsetTarget + 1, 0));
        
        // Base case: There is exactly 1 way to make a sum of 0 with 0 elements
        dp[0][0] = 1;
        
        // Fill the DP table
        for (int i = 1; i <= n; ++i) {
            int currentNum = nums[i - 1];
            for (int j = 0; j <= subsetTarget; ++j) {
                // Choice 1: Exclude the current number
                dp[i][j] = dp[i - 1][j];
                
                // Choice 2: Include the current number (if it fits)
                if (j >= currentNum) {
                    dp[i][j] += dp[i - 1][j - currentNum];
                }
            }
        }
        
        return dp[n][subsetTarget];
    }
};