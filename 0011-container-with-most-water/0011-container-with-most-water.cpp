class Solution {
public:
// first of 
// writing my thoughts 

// in the last it will be min(height[i], height[j])  
    int maxArea(vector<int>& height) {
        
        int i = 0; 
        int j = height.size() - 1;

        int res = 0;

        while (i < j) {
            res = max(res, min(height[i], height[j]) * (j-i));

            if(height[i] <= height[j]) {
                i++;
            }
            else {
                j--;
            }

        }

        return  res;
    }
};