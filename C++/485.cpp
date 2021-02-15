class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0, l = -1, r = 0, n = nums.size();
        while (r < n) {
            if (nums[r] != 1) {
                l = r;
                r++;
                continue;
            }
            // l = r;
            // while (l >= 0 && nums[l] == 1) {
            //     l--;
            // }
            res = max(res, r - l);
            r++;
        }
        return res;
    }
};