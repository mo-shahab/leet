class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        // this is the count of the interval that can be removed
        int count = 0;

        // this will sort the intervals
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            // a and b are two intervals
            return a[1] < b[1];
        });

        vector<int> prev = intervals[0];


        int i = 1;

        while(i < intervals.size())
        {
            vector<int> interval = intervals[i];

            if( interval[0] < prev[1])
            {
                //prev[1] = max(prev[1], interval[1]);
                count++;
            }
            else
            {
                prev = interval;
            }
            i++;
        }

        return count;
    }
};