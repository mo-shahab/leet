class Solution {
public:
    int jump(vector<int>& nums) {

        int res = 0, l = 0, r = 0;

        while(r < nums.size() - 1)
        {
            int reach = 0;

            for(int i=l; i < r+1; i++)
            {
                reach = max(reach, i + nums[i]);
            }

            l = r + 1;
            r = reach;

            res++;

        }
        
        return res;
        // see this is how it will be there right ?? 
    }
};