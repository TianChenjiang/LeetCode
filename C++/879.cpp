class Solution {
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        int MOD = pow(10, 9) + 7;
        int workNum = group.size();
        int dp[101][101][101]; //dp[i][j][k]表示对于前i个工作，需要不超过j个员工，产生利润至少为k的方案数
        for (int i = 0; i <= n; i++) dp[0][i][0] = 1;
        for (int i = 1; i <= workNum; i++) {
            int members = group[i-1], curProfit = profit[i-1];
            for (int j = 0; j <= n; j++) {
                for (int k = 0; k <= minProfit; k++) {
                    dp[i][j][k] = dp[i-1][j][k];
                    if (j >= members) dp[i][j][k] += dp[i-1][j - members][max(0, k-curProfit)];
                    dp[i][j][k] %= MOD;
                }
            }
        }
        return dp[workNum][n][minProfit];
    }
};