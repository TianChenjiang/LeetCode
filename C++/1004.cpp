class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int n = A.size(), l = 0, r = 0, res = 0, usedK = 0;
        while (r < n) {
            if (A[r] == 0) usedK++;
            while (usedK > K) {
                if (A[l] == 0) usedK--;
                l++;
            }
            res = max(r - l + 1, res);
            r++;
        }
        return res;
    }
};