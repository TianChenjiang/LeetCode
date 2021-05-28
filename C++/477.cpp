class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int res = 0, n = nums.size();
        for (int i = 0; i < 32; i++) {
            int tmp = 0;
            for (int num : nums) {
                if (num & (1 << i)) tmp++;
            }
            res += tmp * (n - tmp);
        }
        return res;
    }

};