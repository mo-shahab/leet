class Solution {
public:
    int characterReplacement(string s, int k) {
        int start = 0, end = 0;
        vector<int> count(128, 0);
        int maxFreq = 0;
        int result = 0;

        for(; end < s.length(); end++){
            count[s[end]]++;
            maxFreq = max(maxFreq, count[s[end]]);
            if((end - start + 1) - maxFreq > k){
                count[s[start]]--;
                start++;
            }

            result = max(result, (end-start + 1));
        }

        return result;
    }
};
