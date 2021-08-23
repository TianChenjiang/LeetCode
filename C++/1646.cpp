class Solution {
public:
    int getMaximumGenerated(int n) {
        int res = 0;
        vector<int> vec(n+1);
        for (int i = 0; i < n + 1; i++) {
            if (i <= 1) vec[i] = i;
            if (i % 2 == 0) vec[i] = vec[i / 2];
            else vec[i] = vec[i / 2] + vec[i / 2 + 1];
            res = max(res, vec[i]);
        }
        return res;
    }
    // int getGenerated(int n) {
    //     if (n <= 1) return n;
    //     if (n % 2 == 0) return getGenerated(n / 2);
    //     else return getGenerated(n / 2) + getGenerated(n / 2 + 1);
    // }
};q