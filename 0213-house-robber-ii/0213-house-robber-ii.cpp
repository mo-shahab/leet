class Solution {
public:
    int helper(vector<int>& nums, int start, int end) {
        int n = end - start;
        if (n == 0) return 0;
        if (n == 1) return nums[start];

        vector<int> dp(n);
        dp[0] = nums[start];
        dp[1] = max(nums[start], nums[start + 1]);

        for (int i = 2; i < n; i++) {
            // i is our local index for 'dp', 
            // but we pull from 'nums' using the 'start' offset
            dp[i] = max(dp[i - 1], nums[start + i] + dp[i - 2]);
        }

        return dp[n - 1];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        
        // Scenario 1: Houses 0 to n-2
        // Scenario 2: Houses 1 to n-1
        return max(helper(nums, 0, n - 1), helper(nums, 1, n));
    }
};