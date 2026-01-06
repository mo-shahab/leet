class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;

        int i = 0; 
        int j = 1;

        while (i < prices.size()) {
            if(j < prices.size() && prices[j] - prices[i] > 0) {
                res = max(res, prices[j] - prices[i]);
                j++;
            }
            else {
                i = j;
                j++;
            }
        }

        return res;
    }
};