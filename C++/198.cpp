/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        //dp[i] = dp[i-2] + nums[i]
        int len = nums.size();
        int* dp = new int[len];
        if (len == 0) {
            return 0;
        }
        if (len == 1) {
            return nums[0];
        }
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < len; i++) {
            dp[i] = max(dp[i-2] + nums[i], dp[i-1]);
            
        }
        return dp[len-1];
    }
};
// @lc code=end

