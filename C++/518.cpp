class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int> dp(amount+1);
        dp[0] = 1;
        for (int i = 1; i <= n; i++) { 
            int coin = coins[i-1];
            for (int j = coin; j <= amount; j++) {
                dp[j] += dp[j-coin];
            }
        }
        return dp[amount];
    }
};