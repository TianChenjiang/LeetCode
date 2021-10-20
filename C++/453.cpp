class Solution {
public:
    int minMoves(vector<int>& nums) {
        int res = 0;
        int min = *min_element(nums.begin(), nums.end());
        for (int num : nums) res += num - min;
        return res;
    }
};