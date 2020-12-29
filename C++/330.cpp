class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int res = 0;
        long miss = 1, i = 0;
        while (miss <= n) {
            if (i < nums.size() && miss >= nums[i]) {
                miss += nums[i++];
            } else {
                res++;
                miss += miss;
            }
        }
        return res;
    }
};