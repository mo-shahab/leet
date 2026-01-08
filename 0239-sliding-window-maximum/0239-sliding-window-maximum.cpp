class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int j = 0; 

        int max_curr = INT_MIN;
        vector<int> max_elem_window;

        deque<int> dq;

        while(j < nums.size()) {
            if(!dq.empty() && dq.front() < j - k + 1)
            {
                dq.pop_front();
            }

            while(!dq.empty() && nums[dq.back()] < nums[j]) 
            {
                dq.pop_back();
            }

            dq.push_back(j);

            if(j >= k - 1) {
                max_elem_window.push_back(nums[dq.front()]);
            }

            j++;
        }


        return max_elem_window;

    }
};