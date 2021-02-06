class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int res = INT_MAX, curRes = 0, n = cardPoints.size();
        // 相当于最后保留 n - k 大小的windoow
        int l = 0, r = 0, size = n - k;
        int sum = accumulate(cardPoints.begin(), cardPoints.end(), 0);
        if (k == n) return sum;
        while (r < n) {
            curRes += cardPoints[r];
            while (r - l + 1 > size) {
                curRes -= cardPoints[l];
                l++;
            }
            r++;
            if (r - l == size) res = min(res, curRes);
        }
        return sum - res;
    }
};