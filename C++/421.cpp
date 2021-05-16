class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int n = nums.size(), res = 0, mask = 0;
        for (int i = 30; i >= 0; i--) {
            mask |= (1 << i);
            unordered_set<int> s;
            for (int num : nums) {
                s.insert(num & mask);
            }
            int t = res | (1 << i);
            for (int prefix : s) {
                if (s.count(t ^ prefix)) {
                    res = t;
                    break;
                }
            }
        }
        return res;
    }
};