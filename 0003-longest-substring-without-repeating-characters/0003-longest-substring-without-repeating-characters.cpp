class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0;
        int j = 0;     

        vector<int> counts(128, 0);

        int max_length = 0;

        while(j < s.size()) {
            counts[s[j]]++; // aggresively increase the right pointer no matter what 

            // now other condition comes in here 
            while(counts[s[j]] > 1) {
                counts[s[i]]--;
                i++;
            }

            max_length = max(max_length, j - i + 1);
            j++;
        }

        return max_length;
    }
};

/*
int lengthOfLongestSubstringTwoDistinct(string s) {
        vector<int> map(128, 0);
        int counter=0, begin=0, end=0, d=0; 
        while(end<s.size()){
            if(map[s[end++]]++==0) counter++;
            while(counter>2) if(map[s[begin++]]--==1) counter--;
            d=max(d, end-begin);
        }
        return d;
    }
*/
