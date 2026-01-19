class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> counts(128, 0);
        int counter = 0; // will track the characters needed and such
        int min_window = INT_MAX;
        int start = 0;

        for(char c: t) {
            counts[c]++;
            counter++;
        }

        int i = 0;
        int j = 0;
        
        while(j < s.size()) {
            if(counts[s[j]] > 0) {
                counter--;
            }

            counts[s[j]]--;

            while(counter == 0) {
                if(j - i + 1 < min_window)
                {
                    min_window = j - i + 1;
                    start = i;
                }

                counts[s[i]]++;
                if(counts[s[i]] > 0) counter++;
                i++;
            }
            
            j++;
        }


        return min_window == INT_MAX ? "": s.substr(start, min_window);


    }
};