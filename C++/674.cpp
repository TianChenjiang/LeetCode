class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        const int N = 10001;
        int res = 0, cnt = 1, n = nums.size();
        if (n <= 1) return n;
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i-1]) {
                cnt++;
            } else {
                cnt = 1;
            }
            res = max(res, cnt);
        }
        return res;
    }
};