class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int up = 0, down = n-1, right = n-1, left = 0;
        int curDir = 0;
        vector<vector<int>> dirs = {{0,1}, {1,0},{0,-1},{-1,0}};
        int x = 0, y = 0;
        for (int i = 1; i <= n * n; i++) {
            res[x][y] = i;
            if (curDir == 0 && y == right) {
                curDir++;
                up++;
            } else if (curDir == 1 && x == down) {
                curDir++;
                right--;
            } else if (curDir == 2 && y == left) {
                curDir++;
                down--;
            } else if (curDir == 3 && x == up) {
                curDir++;
                left++;
            }

            curDir %= 4;
            x += dirs[curDir][0];
            y += dirs[curDir][1];
        }
        return res;
    }
};