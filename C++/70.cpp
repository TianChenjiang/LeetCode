/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */

// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
         //dp[n] = dp[n-2] + 2
        int *dp = new int[n+1];
        for (int i = 0; i <= n; i++) {
            if (i <= 2) 
                dp[i] = i;
            else 
                dp[i] = dp[i-2] + dp[i-1];
        }
        return dp[n];
    }
};
// @lc code=end

