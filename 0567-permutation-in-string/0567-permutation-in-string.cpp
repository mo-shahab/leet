class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> freq(128, 0); // this will store frequency of substr
        vector<int> freq1(128, 0);

        for(int i = 0; i < s1.size(); i++) {
            freq[s1[i]]++;
        }

        int i = 0;
        int j = 0;

        while(j < s2.size()) {
            freq1[s2[j]]++;

            if(j - i + 1 > s1.size()) {
                freq1[s2[i]]--;
                i++;
            }

            j++;
            if(freq1 == freq) return true;
        }

        return false;
    }
};