class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (check(nums, i)) return true;
        }
        return false;
    }

    bool check(vector<int>& nums, int start) {
        int next = start, n = nums.size();
        int len = 1;
        bool isPositive = nums[start] > 0 ? true : false;
        while (true) {
            if (len > n) return false;
            next = ((next + nums[next]) % n + n) % n;
            if (isPositive && nums[next] < 0) return false;
            if (!isPositive && nums[next] > 0) return false;
            if (next == start) return len > 1;
            len++;
        }
        return true;
    }
};