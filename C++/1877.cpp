class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int l = 0, r = n - 1;
        int res = 0;
        while (l < r) {
            res = max(res, nums[l] + nums[r]);
            l++; r--;
        }
        return res;
    }
};