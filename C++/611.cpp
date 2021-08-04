class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int res = 0, n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int mn = abs(nums[i] - nums[j]), mx = nums[i] + nums[j];
                auto it = lower_bound(nums.begin() + j + 1, nums.end(), mx);
                res += it - (nums.begin() + j + 1);
            }
        }
        return res;
    }
};