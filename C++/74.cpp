class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size(), column = matrix[0].size();
        int targetRow = row-1;
        for (int i = 0; i < row; i++) {
            if (matrix[i][0] > target) {
                targetRow = i-1;
                break;
            }
        }
        if (row == 1) targetRow = 0;
        if (targetRow == -1) return false;

        vector<int> vec(matrix[targetRow]);

        //在targetRow做二分
        int lo = 0, hi = column-1;
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            if (vec[mid] > target) {
                hi--;
            } else if (vec[mid] < target) {
                lo++;
            } else return true;
        }
        return false;
    }
};