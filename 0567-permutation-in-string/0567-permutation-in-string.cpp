class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // steps to solve this thing
        //
        // first count the occurrences of each character in s1 then create the
        // window (fixed size) of the size of the string s1;
        //
        // now the problem comes in moving the window forward
        //
        //
        // here are the conditions that i think when the window should be moved
        // forward if none of the characters in the s2 exist in the vector of
        // occurrences move foward with j+1
        //
        // if any character exists in the window then move the window where
        // this character is the first character in the windw


        vector<int> count(128, 0);
        vector<int> window_count(128, 0);

        for(int i = 0; i < s1.length(); i++){
            count[s1[i]]++;
        }

        int i = 0;
        int j = 0;

        while(j < s2.length()){
            window_count[s2[j]]++;

            if((j - i + 1) > s1.size()) {
                window_count[s2[i]]--;
                i++;
            }

            if(window_count == count){
                return true;
            }
            
            j++;
        }

        return false;
    }
};
