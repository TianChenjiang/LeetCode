class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, INT_MAX);
        vector<int> completeSquareNums;
        for (int i = 1; i * i <= n; i++) {
            completeSquareNums.push_back(i*i);
        }

        dp[0] = 0;
        for (int i = 1; i <= completeSquareNums.size(); i++) {
            int num = completeSquareNums[i-1];
            for (int j = num; j <= n; j++) {
                dp[j] = min(dp[j], dp[j - num] + 1);
            }
        }
        return dp[n];
    }
};