class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int row = -1;
        for (int i = 0; i < m; i++) {
            if (matrix[i][0] <= target && target <= matrix[i].back()) {
               int l = 0, r = n;
                while (l < r) {
                    int mid = l + (r - l) / 2;
                    if (matrix[i][mid] == target) return true;
                    if (target < matrix[i][mid]) r = mid;
                    else l = mid + 1;
                }
            }
        }
        return false;
    }
};