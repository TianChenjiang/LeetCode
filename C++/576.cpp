class Solution {
public:
    int MOD = pow(10, 9) + 7;
    const int K = 51, M = 51, N = 51;
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int dp[K][M][N];
        memset(dp, 0, sizeof(dp));
        for (int k = 1; k <= maxMove; k++) {
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    long long up = (j == 0) ? 1 : dp[k-1][i][j-1];
                    long long down = (j == n-1) ? 1 : dp[k-1][i][j+1];
                    long long left = (i == 0) ? 1 : dp[k-1][i-1][j];
                    long long right = (i == m-1) ? 1 : dp[k-1][i+1][j];
                    dp[k][i][j] = (up + down + left + right) % MOD;
                }
            }
        }
        return dp[maxMove][startRow][startColumn];
    }
};