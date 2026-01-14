class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<int> sub;
        vector<vector<int>> subs;

        backtrack(candidates, subs, sub, target, 0, 0);
        return subs;

    }

    void backtrack(vector<int>& nums, vector<vector<int>>& subs, vector<int>& sub, int target, int i , int sum)
    {
        if(sum == target)  {
            subs.push_back(sub);
            return;
        }
        if(sum > target) {
            return;
        }

        for(int j = i; j < nums.size(); j++)
        {
            if(j > i && nums[j] == nums[j-1]) continue;
            sum += nums[j];
            sub.push_back(nums[j]);
            backtrack(nums, subs, sub, target, j + 1, sum);
            sum -= nums[j];
            sub.pop_back();
        }
    }
};