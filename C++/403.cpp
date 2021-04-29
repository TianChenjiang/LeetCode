class Solution {
public:
    bool canCross(vector<int>& stones) {
        // dp[i][j]表示当前第i块石头，是上一次跳的距离为j跳过来的
        int dp[2001][2002];
        memset(dp, 0, sizeof(dp));
        int n = stones.size();
        dp[0][0] = 1;
        for (int i = 1; i < n; i++) {
            if (stones[i] - stones[i-1] > i) return false;
        }
        // 最后需要判断 dp[i-1][k]是否为true
        for (int i = 1; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                int dis = stones[i] - stones[j];
                if (dis > j + 1) break;
                dp[i][dis] = dp[j][dis-1] || dp[j][dis] || dp[j][dis+1];
                if (i == n-1 && dp[i][dis]) return true;
            }
        }
        return false;
    }
};