class Solution {
public:
    int arrangeCoins(int n) {
        for (int i = 1; i <= n; i++) {
            if ((long long)i * (i + 1) / 2 > n) return i - 1;
        }
        return 1;
    }
};