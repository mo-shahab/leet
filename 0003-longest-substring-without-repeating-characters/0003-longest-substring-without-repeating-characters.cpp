class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> last_seen(128, -1);
        int start = 0;
        int result = 0;

        for(int end = 0; end < s.size(); end++){
            if(last_seen[s[end]] >= start){
                start = last_seen[s[end]] + 1;
            }

            last_seen[s[end]] = end;
            result = max(result, end - start + 1);
        }

        return result;
    }
};