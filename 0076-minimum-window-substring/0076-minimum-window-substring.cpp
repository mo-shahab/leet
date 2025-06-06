class Solution {
public:
    string minWindow(string s, string t) {
        
        vector<int> have_vec(128, 0);
        vector<int> need_vec(128, 0);

        int have = 0, need = 0;

        for(auto ch: t){
            if(need_vec[ch] == 0){
               need++; 
            }
            need_vec[ch]++;
        }

        int i = 0, j = 0;

        pair<int, int> res; // stores the indices of the result substring;

        int min_len = INT_MAX;
        int min_start = 0;

        while (j < s.size()) {
            char ch = s[j];
            have_vec[ch]++;
        
            if (need_vec[ch] > 0 && have_vec[ch] == need_vec[ch]) {
                have++; 
            }
        
            while (have == need) {
                if (j - i + 1 < min_len) {
                    min_len = j - i + 1;
                    min_start = i;
                }
                char left_char = s[i];
                have_vec[left_char]--;
        
                if (need_vec[left_char] > 0 && have_vec[left_char] < need_vec[left_char]) {
                    have--;
                }
                i++;
            }
    
            j++; 
        }


        return min_len == INT_MAX ? "" : s.substr(min_start, min_len);
    }
};