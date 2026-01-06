class Solution {
public:
    int characterReplacement(string s, int k) {
        
        // in the problems like this 

        // dont do any operations on the item just iterate over them and solve like you would normally do 
        

        // in this case just find the window + k 
        // keep track of the maximum frequency item so that 
        // basically y ou have to replace the items less than those maximum frequency ones and stuff 

        int start = 0, end = 0;

        vector<int> freq(128, 0); // because in here you are finding the frequency of the stuff and all 

        int max_freq = 0;
        int res = 0;

        for(; end < s.size(); end++) {
            freq[s[end]]++;
            max_freq = max(max_freq, freq[s[end]]);

            if((end - start + 1) - max_freq > k) {
                
                freq[s[start]]--; // reducing the size of the window
                start++;
            }

            res = max(res, (end - start + 1));
        }

        return res;
    }
};