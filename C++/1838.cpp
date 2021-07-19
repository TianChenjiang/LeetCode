class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int res = 1, n = nums.size();
        sort(nums.begin(), nums.end());
        unordered_map<int, int> m;
        for (int i = 0; i < n; i++) m[nums[i]]++;
        for (int i = 0; i < n; i += m[nums[i]]) {
            int cur = m[nums[i]], curK = k;
            for (int j = i - 1; j >= 0; j--) {
                int diff = nums[i] - nums[j];
                if (curK >= diff) curK -= diff;
                else break;
                cur++;
            }
            res = max(cur, res);
        }
        return res;
    }
};