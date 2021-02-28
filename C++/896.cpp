class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        int n = A.size();
        if (n == 1) return true;

        bool isIncreasing = false;

        for (int i = 1; i < n; i++) {
            if (A[i-1] < A[i]) {
                isIncreasing = true;
                break;
            }
            else if (A[i-1] > A[i]) {
                break;
            } else continue;
        }

        if (isIncreasing) {
            for (int i = 1; i < n; i++) {
                if (A[i-1] > A[i]) return false;
            }
        } else {
            for (int i = 1; i < n; i++) {
                if (A[i-1] < A[i]) return false;
            }
        }
        return true;
    }
};