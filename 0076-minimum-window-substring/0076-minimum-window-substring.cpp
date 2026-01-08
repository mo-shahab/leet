class Solution {
public:
    string minWindow(string s, string t) {
        int left = 0;
        int right = 0;
        int minLen = INT_MAX; // this will keep the minimum window thing 

        vector<int> counts(128, 0); // counts of each character in the window 
        int charactersNeeded = t.size(); 
        int startIndex = 0;

        for(auto c: t) counts[c]++;

        while(right < s.size()) {
            if(counts[s[right]] > 0) charactersNeeded--; // if the character from t is already in the window then dec that bs. 
            counts[s[right]]--; // we now have this character in the window
            right++;

            // when we come to this , we already have all the characters from t in the window
            // now we try to see if we can shrink the size of the sliding window
            while(charactersNeeded == 0) {

                if(minLen > right - left) {
                    minLen = right - left;
                    startIndex = left;
                }

                counts[s[left]]++;
                if(counts[s[left]] > 0) charactersNeeded++;
                left++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(startIndex, minLen);
    }
};