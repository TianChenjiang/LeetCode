class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int res = 0, n = nums.size(), sum = 0;
        unordered_map<int, int> m({{0,-1}});
        for (int i = 0; i < n; i++) {
            sum += (nums[i] == 0) ? -1 : 1;
            if (m.find(sum) != m.end()) res = max(res, i - m[sum]);
            else m[sum] = i;
        }
        return res;
    }
};