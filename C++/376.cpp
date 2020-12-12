class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int res = 1, n = nums.size();
        if (n <= 1) return n;
        int preDiff = 0, curDiff = 0;
        bool isFirst = true;
        for (int i = 1; i < n; i++) {
            curDiff = nums[i] - nums[i-1];
            if (curDiff != 0 && isFirst || curDiff * preDiff < 0) {
                isFirst = false;
                preDiff = curDiff;
                res++;
            }
        }
        return res;
    }
};