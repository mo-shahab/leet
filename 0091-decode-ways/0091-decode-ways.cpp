class Solution {
public:
    int numDecodings(string s) {
        vector<int> memo(s.size() + 1, 0);
        int res = 0;
        res = recursion(s, 0, memo);      
        return res;
    }

    int recursion(string s, int pos, vector<int> &memo){
        if (pos == s.size()) return 1;
        if (s[pos] == '0') return 0;
        if (pos == s.size() -1) return 1;
        if (memo[pos] > 0) return memo[pos];

        string b = s.substr(pos, 2);

        int way1 = recursion(s, pos+1, memo);
        int way2 = 0;

        if(stoi(b) <= 26 && stoi(b) > 0) {
            way2 = recursion(s, pos+2, memo);
        }

        memo[pos] = way1 + way2;
        return memo[pos];
    }
};