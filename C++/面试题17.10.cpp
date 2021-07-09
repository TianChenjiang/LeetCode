class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = nums[0], cnt = 0;
        for (int num : nums) {
            if (num == candidate) cnt++;
            else cnt--;
            if (cnt < 0) {
                candidate = num;
                cnt = 1;
            }
        }

        cnt = 0;
        for (int num : nums) {
            if (num == candidate) cnt++;
        }
        return (cnt > nums.size() / 2) ? candidate : -1;
    }
};