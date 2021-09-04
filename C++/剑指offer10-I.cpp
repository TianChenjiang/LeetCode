class Solution {
public:
    int fib(int n) {
        if (n <= 1) return n;
        int MOD = pow(10, 9) + 7;
        vector<int> dp(n+1);
        dp[0] = 0, dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            dp[i] = (dp[i-1] + dp[i-2]) % MOD;
        }
        return dp[n];
    }
};