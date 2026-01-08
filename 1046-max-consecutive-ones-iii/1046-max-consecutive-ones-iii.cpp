class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i = 0;
        int j = 0;

        int zeroCount = 0 ;
        int maxLen = 0;

        while(j < nums.size()) {
            if(nums[j] == 0) zeroCount++;

            while(zeroCount - k > 0) {
                if(nums[i] == 0) zeroCount--;
                i++;
            }

            maxLen = max(maxLen, j - i + 1);
            j++;
        }

        return maxLen;
    }
};