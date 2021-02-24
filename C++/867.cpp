class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int r = matrix.size(), c = matrix[0].size();
        vector<vector<int>> res(c);
        for (int i = 0; i < c; i++) {
            for (int j = 0; j < r; j++) {
                res[i].push_back(matrix[j][i]);
            }
        }
        return res;
    }
};