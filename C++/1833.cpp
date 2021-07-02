class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        // int n = costs.size();
        // vector<vector<int>> dp(n + 1, vector<int>(coins + 1)); //前i件物品，不超过j能买的最大数量
        // dp[0][0] = 0;
        // for (int i = 1; i <= n; i++) {
        //     int cost = costs[i-1];
        //     for (int j = 0; j <= coins; j++) {
        //         dp[i][j] = dp[i-1][j];
        //         if (j >= cost) dp[i][j] = max(dp[i][j], dp[i-1][j-cost] + 1);
        //     }
        // }
        // return dp[n][coins];
        sort(costs.begin(), costs.end());
        int n = costs.size(), curCoin = 0, res = 0;
        for (int i = 0; i < n; i++) {
            if (curCoin + costs[i] <= coins) {
                res++;
                curCoin += costs[i];
            } else break;
        }
        return res;
    }
};