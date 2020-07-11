class Solution {
public:
    // -4 -1, -1 0 1 2
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int target = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > target) break;
            int other = target - nums[i];
            int l = i+1, r = nums.size()-1;
            while (l < r) {
                int left = nums[l], right = nums[r];
                if (nums[l] + nums[r] < other) {
                    l++;
                } else if (nums[l] + nums[r] > other) {
                    r--;
                } else {
                    res.push_back({nums[i], nums[l], nums[r]});
                    while (l < r && nums[l] == left) l++;
                    while (l < r && nums[r] == right) r--;
                }
            }
            int cur = nums[i];
            while (i < nums.size() && nums[i] == cur) i++;
            i-=1;
            // while (i < nums.size() && nums[++i] == nums[i]);
        }
        return res;
    }
};