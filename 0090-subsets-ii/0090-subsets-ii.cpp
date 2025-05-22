class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        vector<vector<int>> result;
        vector<int> subset;

        sort(nums.begin(), nums.end());
        dfs(nums, result, subset, 0);
        return result;
    }

    void dfs(
        vector<int>& nums, 
        vector<vector<int>>& result, 
        vector<int>& subset, 
        int start
    )
    {
        result.push_back(subset);    

        for(int i = start; i < nums.size(); i++)
        {
            //if(used[i]) continue;
            if(i > start && nums[i] == nums[i-1]) continue;
            subset.push_back(nums[i]);
            dfs(nums, result, subset, i+1);
            subset.pop_back();
        }
    }
};