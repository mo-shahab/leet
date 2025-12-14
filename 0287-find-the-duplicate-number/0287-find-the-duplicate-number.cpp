class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, int> hashmap; // will store count of each items

        for(auto num: nums) {
            hashmap[num]++;
        }

        for(auto item: hashmap) {
            if(item.second > 1){
                return item.first;
            }
        }

        return 0;
    }
};