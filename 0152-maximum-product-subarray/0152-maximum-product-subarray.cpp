class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int global_product = nums[0];

        int max_curr_product = 1;
        int min_curr_product = 1;

        for(int i = 0; i < nums.size(); i++)
        {
            int temp = max_curr_product;
            max_curr_product = max(nums[i], max(max_curr_product * nums[i], min_curr_product * nums[i]));
            min_curr_product = min(nums[i], min(temp * nums[i], min_curr_product * nums[i]));

            global_product = max(global_product, max(max_curr_product, min_curr_product));
        }

        return global_product;
    }
};