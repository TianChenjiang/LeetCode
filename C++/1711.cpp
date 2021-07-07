class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        int MOD = pow(10, 9) + 7;
        int n = deliciousness.size();
        long long res = 0;
        int maxSum = *max_element(deliciousness.begin(), deliciousness.end()) * 2;
        unordered_map<int, int> m;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= maxSum; j *= 2) {
                if (m.count(j - deliciousness[i])) res = (res + m[j-deliciousness[i]]) % MOD;
            }
            m[deliciousness[i]]++;
        }
        return (int) res % MOD;
    }

    bool is2Power(long long n) {
        return (n & (n-1)) == 0;
    }
};