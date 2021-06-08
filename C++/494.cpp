class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        // Sum(P) - Sum(N) = target
        // Sum(P) + Sum(N) + Sum(P) - Sum(N) = target + Sum(P) + Sum(N)
        // 2 * Sum(P) = target + Sum
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int pTarget = (target + sum) / 2;
        int dp[1001];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        if (sum < target || (target + sum) % 2 != 0) return 0;
        for (int num : nums) {
            for (int i = pTarget; i >= num; i--) {
                dp[i] += dp[i-num];
            }
        }
        return dp[pTarget];
    }
};