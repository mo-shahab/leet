class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0;
        int j = 0;    
        int maxLen = 0;
         

        vector<int> freq(128, -1);

        while(j < s.size()) {
            if(freq[s[j]] < i) {
                freq[s[j]] = j;
                j++;
            } else {
                i = freq[s[j]] + 1;
                freq[s[j]] = j;
                j++;
            }
            maxLen = max(maxLen, j - i);
        }

        return maxLen;
    }
};