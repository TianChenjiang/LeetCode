class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int n = nums.size();
        map<long long, int> m;
        int l = 0, r = 0;
        while (r < n) {
            if (r - l > k) {
                m.erase(nums[l]);
                l++;
            }
            auto a = m.lower_bound((long long) nums[r] - t);
            if (a != m.end() && r - (*a).second <= k) return true;
            m[nums[r]] = r;
            r++;
        }
        return false;
    }
};