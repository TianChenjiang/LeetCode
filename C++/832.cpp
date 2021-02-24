class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        for (vector<int>& row : A) {
            reverse(row.begin(), row.end());
        }
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[0].size(); j++) {
                A[i][j] ^= 1;
            }
        }
        return A;
    }
};