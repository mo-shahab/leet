class Solution 
{
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        priority_queue<int, vector<int>, greater<int>> min_heap;

        for(int i = 0; i < nums.size(); i++)     
        {
            min_heap.push(nums[i]);
        }

        int j = nums.size();
        while(j > k)
        {
            min_heap.pop();
            j--;
        }

        return min_heap.top();
    }
};