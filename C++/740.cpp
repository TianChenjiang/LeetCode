class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int aggregateNums[10001], dp[10001];
        memset(aggregateNums, 0 ,sizeof(aggregateNums));
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            aggregateNums[nums[i]] += nums[i];
            cnt = max(cnt, nums[i]);
        }
        //dp[i]表示数字i前获得的最大点数
        dp[0] = 0, dp[1] = aggregateNums[1];
        for (int i = 2; i <= cnt; i++) {
            dp[i] = max(dp[i-1], dp[i-2] + aggregateNums[i]);
        }
        return dp[cnt];
    }
};