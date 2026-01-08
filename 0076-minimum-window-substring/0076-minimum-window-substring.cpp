// https://leetcode.com/problems/minimum-window-substring/solutions/26808/here-is-a-10-line-template-that-can-solv-lct0
class Solution {
public:
    string minWindow(string s, string t) {
        // Frequency map to track what we need from string 't'
        vector<int> charCounts(128, 0);
        for (char c : t) {
            charCounts[c]++;
        }

        int left = 0;
        int right = 0;
        int charactersNeeded = t.size();
        
        int minWindowLength = INT_MAX;
        int startIndex = 0;

        // Phase 1: Expand the window
        while (right < s.size()) {
            char currentRight = s[right];

            // If we found a character that's actually in 't', decrement our requirement
            if (charCounts[currentRight] > 0) {
                charactersNeeded--;
            }
            
            // Note: We decrement charCounts even for characters NOT in 't'
            // This creates negative values for extra/unnecessary characters
            charCounts[currentRight]--;
            right++;

            // Phase 2: Shrink the window once it's "valid"
            while (charactersNeeded == 0) {
                int currentWindowSize = right - left;

                // Update our record for the smallest window
                if (currentWindowSize < minWindowLength) {
                    minWindowLength = currentWindowSize;
                    startIndex = left;
                }

                // Move the left pointer to see if we can still stay valid with less
                char currentLeft = s[left];
                charCounts[currentLeft]++;

                // If the count goes above 0, it means we just lost a required character
                if (charCounts[currentLeft] > 0) {
                    charactersNeeded++;
                }

                left++;
            }
        }

        // Final check: did we ever find a valid window?
        return (minWindowLength == INT_MAX) ? "" : s.substr(startIndex, minWindowLength);
    }
};