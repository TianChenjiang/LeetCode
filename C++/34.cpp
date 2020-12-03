class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size() - 1;
        int left, right;
        left = binarySearch(nums, lo, hi, target); //第一个大于等于target的索引
        right = binarySearch(nums, lo, hi+1, target+1)-1;
        if (left >= nums.size() || nums[left] != target) return {-1,-1};
        return {left, right};
    }

    int binarySearch(vector<int> nums, int lo, int hi, int target) {
        while (lo < hi) {
            int mi = (lo + hi) >> 1;
            target <= nums[mi] ? hi = mi : lo = mi + 1;
        }
        return lo;
    }
};