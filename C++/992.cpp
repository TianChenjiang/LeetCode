class Solution {
public:
    int atMostKDistinct(vector<int>& A, int k) {
        int res = 0, n = A.size(), distinct = 0;
        int l = 0, r = 0;
        unordered_map<int, int> m;
        while (r < n) {
            if (m[A[r]]++ == 0) distinct++;
            while (distinct > k) {
                if (--m[A[l]] == 0) distinct--;
                l++;
            }
            res += r - l + 1; 
            r++;
        }
        return res;
    }

    int subarraysWithKDistinct(vector<int>& A, int K) {
        return atMostKDistinct(A, K) - atMostKDistinct(A, K-1);
    }
};