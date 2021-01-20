class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int res = 1, n = nums.size();
        //三负 两负一正 或者三正
        sort(nums.begin(), nums.end());
        if (nums[n-1] < 0) {
            return nums[n-3] * nums[n-2] * nums[n-1];
        } else {
            res *= nums[n-1] * max(nums[0] * nums[1], nums[n-2] * nums[n-3]);
            // res *= nums[n-1];
            // if (nums[0] * nums[1] > nums[n-2] * nums[n-3]) {
            //     res *= nums[0] * nums[1];
            // } else {
            //     res *= nums[n-2] * nums[n-3];
            // }
        }
        return res;
    }
};