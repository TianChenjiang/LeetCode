class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int slow = 2, n = nums.size();
        if (n <= 2) return n;
        for (int fast = 2; fast < n; fast++) {
            if (nums[slow-2] != nums[fast]) {
                nums[slow++] = nums[fast];
            }
        }
        return slow;
    }
};