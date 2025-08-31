class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // consider the sum of each of subset to be k
        // then the combined sum of these two subsets will be k/2
        // now we have to only find one subset 
        int target = 0;
        int sum = 0;

        for(int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
        }

        if (sum % 2 != 0) {
            return false;
        }

        target = sum / 2;

        vector<bool> prev(target + 1, false);

        return subsetSum(nums, target, nums.size(), prev);
    }

    bool subsetSum(vector<int>& nums, int target, int n, vector<bool>& prev)
    {
        prev[0] = true;

        if(nums[0] <= target)
        {
            prev[nums[0]] = true;
        }

        for(int i = 1; i < n; i++)
        {
            vector<bool> curr(target + 1, false);

            curr[0] = true;

            for(int k = 1; k <= target; k++)
            {
                bool notTaken = prev[k];

                bool taken = false;

                if(nums[i] <= k)
                {
                    taken = prev[k - nums[i]];
                }

                curr[k] = notTaken || taken;
            }

            prev = curr;
        }

        return prev[target];
    }
};