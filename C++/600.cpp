class Solution {
public:
    const int N = 31;
    int findIntegers(int n) {
        int res = 0, pre = 0;
        vector<int> dp(N + 1);
        dp[0] = 1; dp[1] = 2;
        for (int i = 2; i < N; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        int k = N;
        while (k--) {
            if (n & (1 << k)) { //当前位是1
                res += dp[k];
                if (pre) return res;
                pre = 1;
            } else pre = 0;
        }
        return ++res;
    }
};