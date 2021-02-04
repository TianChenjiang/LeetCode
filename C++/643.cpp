class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size(), curSum = accumulate(nums.begin(), nums.begin()+k, 0);
        double res = double(curSum) / k;
        for (int i = k; i < n; i++) {
            curSum += (nums[i] - nums[i-k]);
            res = fmax(res, (double(curSum) / k));
        }
        return res;
    }
};