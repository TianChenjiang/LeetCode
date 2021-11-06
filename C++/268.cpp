class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = 0, sum = accumulate(nums.begin(), nums.end(), 0), n = nums.size();
        int expect = n * (n + 1) / 2;
        return expect - sum;
    }
};