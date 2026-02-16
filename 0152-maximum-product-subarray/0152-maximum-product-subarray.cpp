class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // storing max and min product everytime;
        int global_prod = nums[0];

        int min_product = 1;
        int max_product = 1;

        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] < 0) {
                int temp = min_product;
                min_product = max_product;
                max_product = temp;
            }

            min_product = min(nums[i] * min_product, nums[i]);
            max_product = max(nums[i] * max_product, nums[i]);

            global_prod = max(global_prod, max_product);

            if(nums[i] == 0) {
                min_product = 1;
                max_product = 1;
            }
        }

        return global_prod;
    }
};