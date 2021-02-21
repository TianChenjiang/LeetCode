class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int res = 0, n = nums.size();
        int l = 0, r = 0;
        multiset<int> s;
        while (r < n) {
            s.insert(nums[r]);
            while (*s.rbegin() - *s.begin() > limit) {
                s.erase(s.find(nums[l]));
                l++;
            }
            res = max(res, r - l + 1);
            r++;
        }
        return res;
    }
};