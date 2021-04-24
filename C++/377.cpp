class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        unsigned long long dp[1001]; // dp[i]表示target为i的时候的解的个数
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        sort(nums.begin(), nums.end());
        for (int i = 1; i < target + 1; i++) {
            for (int num : nums) {
                if (i >= num) dp[i] += dp[i - num];
                else break;
            }
        }
        return dp[target];
    }
};