class Solution {
public:
    int coinChange(vector<int>& coins, int amount) 
    {
        int dp[amount + 1];
        dp[0] = 0;

        sort(begin(coins), end(coins));

        for(int i = 1; i <= amount; i++)
        {
            dp[i] = INT_MAX;

            for(int coin: coins) 
            {
               /**
                * i -> current amount
                * coin -> current coin
                * checking if the current coin is greater than the current amount
                * why ? because you can only make change for the amount if the denomination
                * in the coin is lesser than the amount ! right  
                */
                if(i - coin >= 0)
                {
                    // this just checks if the subproblem is already solved ? 
                    if(dp[i - coin] != INT_MAX) dp[i] = min(dp[i], dp[i - coin] + 1);
                } 
            }
        }

        if(dp[amount] == INT_MAX) return -1;
        return dp[amount];
    }

};