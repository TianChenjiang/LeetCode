class Solution {
public:
    const int N = 2002;
    int findNumberOfLIS(vector<int>& nums) {
        int dp[N], num[N], len = 0, res = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            dp[i] = num[i] = 1;
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    if (dp[i] < dp[j] + 1) num[i] = num[j];
                    else if (dp[i] == dp[j] + 1) num[i] += num[j];
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            len = max(len, dp[i]);
        }
        for (int i = 0; i < n; i++) {
            if (dp[i] == len) res += num[i];
        }
        return res;
    }
};