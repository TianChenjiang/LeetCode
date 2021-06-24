class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size(), res = 2;
        if (n <= 2) return n;
        for (int i = 0; i < n; i++) {
            int x1 = points[i][0], y1 = points[i][1];
            for (int j = i + 1; j < n; j++) {
                int x2 = points[j][0], y2 = points[j][1];
                int deltaX = x1 - x2, deltaY = y1 - y2;
                // y / x = y3 - y1 / x3 - x1
                int cnt = 2;
                for (int k = j + 1; k < n; k++) {
                    int x3 = points[k][0], y3 = points[k][1];
                    if (deltaY * (x3 - x1) == deltaX * (y3 - y1)) cnt++;
                }
                res = max(cnt, res);
            }
        }
        return res;
    }
};