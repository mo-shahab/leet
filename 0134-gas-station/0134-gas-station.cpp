class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // 1. Calculate the total fuel difference to check for impossibility.
        // If total_gain is negative, no solution exists.
        int total_gain = 0;
        for (int i = 0; i < gas.size(); ++i) {
            total_gain += gas[i] - cost[i];
        }

        if (total_gain < 0) {
            return -1;
        }

        // 2. Single-pass (Greedy) approach to find the unique starting station.
        int current_fuel = 0;
        int start_index = 0;

        for (int i = 0; i < gas.size(); ++i) {
            // Update the current fuel after traveling from 'i' to 'i+1'
            current_fuel += gas[i] - cost[i];

            // If the current fuel drops below zero, the current start_index (and
            // all stations between start_index and i) cannot be the answer.
            // The new potential start must be the next station (i + 1).
            if (current_fuel < 0) {
                // Reset the starting point to the next station
                start_index = i + 1;
                // Reset the fuel tank for the new starting point
                current_fuel = 0;
            }
        }

        // Since we already checked that total_gain >= 0, a solution MUST exist.
        // The start_index found during the single pass is guaranteed to be the correct answer.
        return start_index;
    }
};