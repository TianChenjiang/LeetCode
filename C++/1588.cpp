class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size(), res = 0;
        vector<int> preSum(n + 1);
        for (int i = 1; i <= n; i++) {
            preSum[i] = preSum[i-1] + arr[i-1];
        }
        for (int i = 1; i <= n; i+=2) {
            for (int j = 0; j < n - i + 1; j++) {
                res += preSum[j + i] - preSum[j];
            }
        }
        return res;
    }
};