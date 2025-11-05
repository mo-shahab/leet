class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {

        unordered_set<int> st;

        for(auto triplet: triplets)
        {
            if(triplet[0] > target[0] || triplet[1] > target[1] || triplet[2] > target[2]) continue;

            for(int j=0; j<3; j++) 
            {
                if(triplet[j] == target[j]) st.insert(j);
            }
        }

        return st.size() == 3;
    }
};