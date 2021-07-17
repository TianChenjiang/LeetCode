class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int res = nums[0], cur = nums[0];
        for (int i = 1; i < n; i++) {
            cur = max(nums[i], nums[i] + cur);
            res = max(res, cur);
        }
        return res;
    }
};