class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        sort(A.rbegin(), A.rend());
        for (int i = 0; i < A.size()-2; i++) {
            int a=A[i], b=A[i+1], c=A[i+2];
            if (b + c > a) {
                return a + b + c;
            } else {
                continue;
            }
        }
        return 0;
    }
};