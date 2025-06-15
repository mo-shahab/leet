class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result(n, 0); // Initialize result with zeros
        stack<int> mono_stack;    // Store indices, not temperatures
        
        for (int i = 0; i < n; i++) {
            // While stack is not empty and current temp is warmer than temp at stack top
            while (!mono_stack.empty() && temperatures[i] > temperatures[mono_stack.top()]) {
                int prev_index = mono_stack.top();
                mono_stack.pop();
                result[prev_index] = i - prev_index; // Days until warmer day
            }
            mono_stack.push(i); // Push current day's index
        }
        
        return result;
    }
};