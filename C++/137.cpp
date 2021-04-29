class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> m;
        for (int num : nums) {
            m[num]++;
        }
        for (auto mm : m) {
            if (mm.second == 1) return mm.first;
        }
        return -1;
    }
};