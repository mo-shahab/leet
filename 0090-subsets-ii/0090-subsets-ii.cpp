class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> sub;
        vector<vector<int>> subs;    

        sort(nums.begin(), nums.end());

        backtrack(nums, subs, sub, 0);
        return subs;
    }

    void backtrack(vector<int>& nums, vector<vector<int>>& subs, vector<int>& sub, int i)
    {
        subs.push_back(sub);

        for(int j = i; j < nums.size(); j++)
        {
            if(j > i && nums[j-1] == nums[j]  ) continue;

            sub.push_back(nums[j]);
            backtrack(nums, subs, sub, j + 1);
            sub.pop_back();
        }
    }
};