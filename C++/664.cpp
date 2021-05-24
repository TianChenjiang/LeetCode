class Solution {
public:
    int strangePrinter(string s) {
        int n = s.size();
        int dp[101][101];
        // dp[i][j]表示i到j区间内的打印次数
        for (int i = n - 1; i >= 0; i--) {
            dp[i][i] = 1;
            for (int j = i + 1; j < n; j++) {
                if (s[i] == s[j]) dp[i][j] = dp[i][j-1];
                else {
                    // 取dp[i][k]
                    int tmp = 101;
                    for (int k = i; k < j; k++) {
                        tmp = min(tmp, dp[i][k] + dp[k+1][j]);
                    }
                    dp[i][j] = tmp;
                }
            }
        }
        return dp[0][n-1];
    }
};