class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> nums1(nums), nums2(nums);
        nums1.erase(nums1.end()-1);
        nums2.erase(nums2.begin());
        return max(helper(nums1), helper(nums2));
    }

    int helper(vector<int>& nums) {
        int dp[101], n = nums.size();
        if (n <= 2) return *max_element(nums.begin(), nums.end());
        dp[0] = nums[0], dp[1] = max(nums[0], nums[1]);
        int res = dp[1];
        for (int i = 2; i < n; i++) {
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        }
        return dp[n-1];
    }
};