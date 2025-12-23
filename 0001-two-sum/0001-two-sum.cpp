class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashmap;

        for(int i= 0; i< nums.size(); i++) {
            hashmap[nums[i]] = i;
        }

        for(int i =0; i< nums.size(); i++) {
            int complement = target - nums[i]; 

            if(hashmap.count(complement) && i != hashmap[complement]) {
                return {i, hashmap[complement]};
            }
        }

        return {};
    }
};