/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int dp[nums.size()+1];
        int max_num = *max_element(nums.begin(), nums.end());
        for (int i = 0; i < nums.size()+1; i++) {
            dp[i] = max_num;
        }
        int temp = nums[0];
        for (int i = 2; i <= nums.size(); i++) {
           // dp[i]前i个元素的最大子列和
            if (temp + nums[i-1] <= 0 || temp < 0) temp = nums[i-1]>0?nums[i-1]:0;
            else {
                temp += nums[i-1];
                dp[i] = temp;
            }
            cout << temp << " ";
        }
        return *max_element(dp, dp+nums.size()+1);
    }
};
// @lc code=end

