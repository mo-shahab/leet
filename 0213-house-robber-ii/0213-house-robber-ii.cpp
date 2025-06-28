class Solution {
public:
    int rob(vector<int>& nums) {

        if(nums.size() == 1){
            return nums[0];
        }
        
        int n = nums.size();
        return max(helper(nums, 0, n-1), helper(nums, 1, n ));
    }

    int helper(vector<int>& nums, int start, int end) {
        int prev = 0, curr = 0;

        for(int i = start ; i < end; i++) {
            int temp = max(prev + nums[i], curr);
            prev = curr;
            curr = temp;
        }

        return curr;
    }
};