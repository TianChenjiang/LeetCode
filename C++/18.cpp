class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        if (nums.size() < 4) return res;
        for (int i = 0; i < nums.size()-3; i++) {
            // if (nums[i] > target) break;
            for (int j = i+1; j < nums.size()-2; j++) {
                // if (nums[i] + nums[j] > target) break;
                int other = target - nums[i] - nums[j];
                int l = j+1, r = nums.size()-1;
                while (l < r) {
                    int left = nums[l], right = nums[r];
                    if (nums[l] + nums[r] < other) {
                        l++;                       
                    } else if (nums[l] + nums[r] > other) {
                        r--;
                    } else {
                        res.push_back({nums[i], nums[j], nums[l], nums[r]});
                        while (l < r && nums[l] == left) l++;
                        while (l < r && nums[r] == right) r--;
                    }
                }
                while (j < nums.size()-2 && nums[j] == nums[j+1]) j++;
            }
            while (i < nums.size()-3 && nums[i] == nums[i+1]) i++;
        } 
        return res;
    }
};