class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> preSum(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            preSum[i] = preSum[i-1] + nums[i-1];
            // cout << preSum[i] << " ";
        }

        // 前缀和满足余数相同.   sum[i] - sum[j] = n * k
        unordered_set<int> st;
        for (int i = 2; i <= n; i++) {
            int cur = preSum[i-2] % k;
            st.insert(cur);
            if (st.find(preSum[i] % k) != st.end()) return true;
        }
        return false;
    }
};