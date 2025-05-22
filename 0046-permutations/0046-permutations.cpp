class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> subset;
        vector<bool> used(nums.size(), false);

        dfs(nums, result, subset, used, 0);
        return result;
    }
    void dfs(
        vector<int>& nums, 
        vector<vector<int>>& result,
        vector<int>& subset,
        vector<bool> used,
        int start
    )
    {
        if(subset.size() == nums.size()){
            result.push_back(subset);
            return;
        }

        for(int i = 0; i < nums.size(); i++){
            if(used[i]) continue;
            used[i] = true;
            subset.push_back(nums[i]);
            dfs(nums, result, subset, used, i+1);
            subset.pop_back();
            used[i] = false;
        }

    }
};