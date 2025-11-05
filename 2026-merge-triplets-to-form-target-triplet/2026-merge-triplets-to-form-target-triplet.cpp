class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {

        vector<int> merge{0, 0, 0};

        for(auto triplet: triplets)
        {
            if(triplet[0] > target[0] || triplet[1] > target[1] || triplet[2] > target[2]) continue;
            merge = {max(merge[0], triplet[0]), max(merge[1], triplet[1]), max(merge[2], triplet[2])};
        }

        return merge == target;
    }
};