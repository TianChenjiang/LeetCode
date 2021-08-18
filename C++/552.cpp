class Solution {
public:
    int MOD = pow(10, 9) + 7;
    int checkRecord(int n) {
        vector<long> P(n + 1), PorL(n + 1);
        long res = 0;
        P[0] = 1, PorL[0] = 1, PorL[1] = 2; //P[i]表示以P结尾的长度为i的排列数
        for (int i = 1; i <= n; i++) {
            P[i] = PorL[i-1];
            if (i > 1) PorL[i] = (P[i] + P[i-1] + P[i-2]) % MOD;
        }
        res = PorL[n];
        for (int i = 0; i < n; i++) { //第i个位置是A,把数组分为两部分，结果就等于两部分长度对应排列乘积
            res = (res + PorL[i] * (PorL[n - i - 1])) % MOD;
        }
        return res;
    }
};