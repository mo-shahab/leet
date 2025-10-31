class Solution {
public:
    int jump(vector<int>& nums) {

        int jumps = 0;              // Counts the number of jumps taken (our result)
        int current_jump_start = 0; // The start of the current range to explore
        int current_jump_end = 0;   // The end of the current range to explore (farthest reach from the previous jump)

       while(current_jump_end < nums.size() - 1)
        {
            // 1. Initialize for the *next* jump's potential
            int farthest_reach = 0;

            // 2. Explore the current jump's range (Greedy Choice)
            for(int i = current_jump_start; i <= current_jump_end; i++)
            {
                // Calculate the farthest position we can reach from the current index 'i'
                // and update our overall best reach within this range.
                farthest_reach = max(farthest_reach, i + nums[i]);
            }

            // 3. Prepare for the *next* jump (Greedy Jump Taken)
            current_jump_start = current_jump_end + 1; // The next jump will start *after* the current range
            current_jump_end = farthest_reach;         // The new range ends at the farthest point we could reach

            // 4. Increment the jump count
            jumps++;
        }
        
        return jumps; 
    }
};