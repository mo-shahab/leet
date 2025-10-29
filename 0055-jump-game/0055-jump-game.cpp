class Solution {
public:
    bool canJump(vector<int>& nums) {
        int goal = nums.size() - 1;

        int i = nums.size() - 1;

        while(i >= 0)
        {
            if(i + nums[i] >= goal) goal = i ;
            i--;
        }

        if(goal == 0) return true;
        else return false;
    }
};