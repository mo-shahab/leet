class Solution {
public:
    int characterReplacement(string s, int k) {
        int i = 0;
        int j = 0;       

        vector<int> counts(128, 0);
        int maxFreq = 0;
        int result = 0;

        while(j < s.size()) {
            counts[s[j]]++; // agressive right pointer increase

            maxFreq = max(maxFreq, counts[s[j]]); // check if this is the most frequent thign

            // no point in replacing the maximum occureing character just replace what all are least occuring
            // a bit greedy approach
            while((j - i + 1 - maxFreq) > k) {
                counts[s[i]]--;
                i++;
            }
            
            result = max(result, j - i + 1);
            j++;
        }

        return result;
    }
};