class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;
        
        int i = 0;
        int j = 0;

        int prod = 1;
        int numProd = 0;

        while(j < nums.size()) {
            prod *= nums[j];

            while(prod >= k) {
                prod /= nums[i];
                i++;
            }

            numProd += (j - i + 1);
            j++;
        }

        return numProd;
    }
};