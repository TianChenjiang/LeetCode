class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        int n = A.size();
        vector<bool> res(n);
        int num = 0;
        for (int i = 0; i < n; i++) {
            num = ((num << 1) % 5 + A[i]);
            if (num % 5 == 0) res[i] = true;
            else res[i] = false;
        }
        return res;
    }
};