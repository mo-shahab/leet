class Solution {
public:
    int longestSubstring(string s, int k) {
        return longestSubstringHelper(s, 0, s.length(), k);
    }

    int longestSubstringHelper(string& s, int low, int high, int k) {
        if (high - low < k) return 0;

        vector<int> count(128, 0);
        for (int i = low; i < high; i++) {
            count[s[i]]++;
        }

        for (int mid = low; mid < high; ++mid) {
            if (count[s[mid]] < k) {
                int midNext = mid + 1;
                while (midNext < high && count[s[midNext]] < k) midNext++; // skip invalids
                return max(
                    longestSubstringHelper(s, low, mid, k),
                    longestSubstringHelper(s, midNext, high, k)
                );
            }
        }

        // All characters in this range occur at least k times
        return high - low;
    }
};
