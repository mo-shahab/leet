class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int i = 0;
        int j = 0;
        
        int maxLen = 0;
        int zeroCount = 0;

        while(j < nums.size()) {
            if(nums[j] == 0) zeroCount++;
            // shrinking the slinding window logic
            // literally just this
            while(zeroCount > 0) {
                if(nums[i] == 0) zeroCount--;
                i++;
            }

            maxLen = max(maxLen, j - i + 1);
            j++; 
        }

        return maxLen;
    }
};