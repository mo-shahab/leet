class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long neg_cnt = 0, ans = 0, size = matrix.size(), minn = LLONG_MAX;

        for(int i = 0 ; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[0].size(); j++) {
                ans += abs(matrix[i][j]);

                if(matrix[i][j] < 0) neg_cnt++;

                minn = minn < abs(matrix[i][j]) ? minn: abs(matrix[i][j]);
            }
        }

        if(neg_cnt % 2 == 0) return ans;
        else return ans - minn - minn; // one time to remove it from being added, then other time for removing from ever being added 
    }
};