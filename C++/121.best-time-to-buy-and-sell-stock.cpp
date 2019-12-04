/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        for (int i = 0; i < prices.size(); i++) {
            for (int j = i+1; j < prices.size(); j++) {
                int minus = prices[j] - prices[i];
                if (minus > 0) {
                    // dp[i][j] = minus;
                    if (minus > res) 
                        res = minus;   
                }
            }
            
        }
        return res;
    }
};
// @lc code=end

