class Solution {
public:
    bool isPalindrome(string s) {
        vector<char> temp;

        for(int i = 0; i < s.size(); i++) {
            if(isalnum(s[i])) {
                temp.push_back(tolower(s[i]));
            }
        }

        int i = 0; 
        int j = temp.size() - 1;

        while (i <= j) {
            if(temp[i] == temp[j]) {
                i++;
                j--;
            } else {
                return false;
            }
        }

        return true;
    }
};