class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int res = 0, n = nums.size();
        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());
        int l = 0, r = n-1;
        // if (sortedNums == nums) return 0;
        while (l <= r && sortedNums[l] == nums[l]) l++;
        while (l <= r && sortedNums[r] == nums[r]) r--;
        return r - l + 1;
    }
};