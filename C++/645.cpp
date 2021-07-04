class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(2), m(n + 1);
        for (int num : nums) {
            m[num]++;
        }
        for (int i = 1; i <= n; i++) {
            if (!m[i]) res[1] = i;
            if (m[i] == 2) res[0] = i;
        }
        return res;
    }
};