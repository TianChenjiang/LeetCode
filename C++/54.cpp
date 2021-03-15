class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        vector<vector<int>> dirs = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        int curDir = 0, m = matrix.size(), n = matrix[0].size();
        int x = 0,  y = 0; //当前位置
        int up = 0, down = m-1, left = 0, right = n-1;
        while (res.size() < m * n) {
            cout << x << " " << y << endl;
            res.push_back(matrix[x][y]);
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