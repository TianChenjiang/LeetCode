class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n - 1;
        if (nums[right] > nums[left]) return nums[left];
        while (left < right) {
            int mid = (left + right) >> 1;
            nums[0] <= nums[mid] ? left = mid + 1 : right = mid;
        }
        return nums[right];
    }
};