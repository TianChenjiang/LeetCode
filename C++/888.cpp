class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        vector<int> res;
        int Asum = accumulate(A.begin(), A.end(), 0);
        int Bsum = accumulate(B.begin(), B.end(), 0);
        int delta = (Asum - Bsum)/2;

        unordered_set<int> s(A.begin(), A.end());
        for (int b : B) {
            int x = b + delta;
            if (s.count(x)) {
                return {x, b};
            }
        }
        return res;
    }
};