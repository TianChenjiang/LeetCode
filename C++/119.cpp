class Solution {
public:
    vector<int> getRow(int rowIndex) {
        const int N = 35;
        int rec[N][N];
        vector<int> res;
        for (int i = 0; i <= rowIndex; i++) {
            for (int j = 0; j <= i; j++) {
                if (j == 0 || j == i) rec[i][j] = 1;
                else {
                    rec[i][j] = rec[i-1][j-1] + rec[i-1][j];
                }
            }
        }

        for (int i = 0; i <= rowIndex; i++) {
            res.push_back(rec[rowIndex][i]);
        }
        return res;
    }
};