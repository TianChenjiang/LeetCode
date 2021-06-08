class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int sum = accumulate(stones.begin(), stones.end(), 0);
        int target = sum / 2;
        vector<int> dp(target + 1, 0); //表示前i个物品，凑成的总和不超过j
        for (int i = 1; i <= n; i++) {
            int cur = stones[i-1];
            for (int j = target; j >= cur; j--) {
                dp[j] = max(dp[j], dp[j-cur] + cur);
            }
        }
        return abs(sum - 2 * dp[target]);
    }
};