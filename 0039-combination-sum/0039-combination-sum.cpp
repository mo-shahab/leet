class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> sub;
        vector<vector<int>> subsets;
        backtrack(candidates, subsets, sub, 0, target, 0);
        return subsets;
    }

    void backtrack(vector<int>& nums, vector<vector<int>>& subs, vector<int>& sub, int i, int target, int sum)
    {
        if(sum == target)
        {
            subs.push_back(sub);
            return;
        }

        if(sum > target){
            return;
        }
        for(int j = i; j < nums.size(); j++){
            sum += nums[j];
            sub.push_back(nums[j]);
            backtrack(nums, subs, sub, j, target, sum);
            sum -= nums[j];
            sub.pop_back();
        }
    }

};