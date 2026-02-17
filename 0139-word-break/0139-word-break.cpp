class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if(wordDict.size() == 0) return false;

        set<string> dict;
        for(auto w: wordDict) dict.insert(w);

        vector<bool> dp(s.size() + 1, false);

        dp[0] = true;

        for(int i = 0; i < s.size() + 1; i++)
        {
            // prefices
            for(int j = i-1; j>=0; j--){

                if(dp[j]) {

                    string word = s.substr(j, i -j);
    
                    if(dict.find(word) != dict.end()) {
                        dp[i] = true; // that substring is there
                        break;
                    }
                }

            }
        }

        return dp[s.size()];
    }
};