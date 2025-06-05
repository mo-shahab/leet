class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.length();
        unordered_map<string, int> hashmap;
        vector<string> result;

        if( n < 10){
            return result;
        }
        for(int i = 0; i <= n - 10; i++){
            hashmap[s.substr(i, 10)]++;
        }

        for(auto& p: hashmap){
            if(p.second > 1){
                result.push_back(p.first);
            }
        }

        return result;
    }
};