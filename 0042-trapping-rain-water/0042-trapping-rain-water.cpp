class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() == 0){
            return 0;
        }

        if(height.size() == 1){
            return 0;
        }


        int l_pointer = 0;
        int r_pointer = height.size()-1;
        int res = 0;

        int l_max = height[l_pointer];
        int r_max = height[r_pointer];

        while(l_pointer < r_pointer){
            if(height[l_pointer] < height[r_pointer]){
                l_pointer++;
                l_max = max(l_max, height[l_pointer]);
                res += l_max - height[l_pointer];
            }
            else {
                r_pointer--;
                r_max = max(r_max, height[r_pointer]);
                res += r_max - height[r_pointer];
            }
        }

        return res;
    }
};