class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int n = customers.size(), res = 0;
        int cur = 0, maxSatisfiedOfNotAngryDiff = 0;
        int maxIndex = 0;
        int maxDiff = 0, diff = 0;

        // 计算哪几分钟不生气
        for (int i = 0; i < X; i++) diff += grumpy[i] * customers[i];
        maxDiff = diff;
        for (int i = 1; i < n - X + 1; i++) {
            diff -= grumpy[i-1] * customers[i-1];
            diff += grumpy[i + X - 1] * customers[i + X - 1];
            maxDiff = max(diff, maxDiff);
        }

        cout << maxDiff;
        for (int i = 0; i < n; i++) {
            res += (grumpy[i] ^ 1) * customers[i];
        }
        res += maxDiff;
        return res;
    }
};