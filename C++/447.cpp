class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int res = 0, n = points.size();
        if (n < 3) return 0;
        for (int i = 0; i < n; i++) {
            unordered_map<int, int> m;
            for (int j = 0; j < n; j++) {
                m[dis(points[i], points[j])]++;
            }
            for (auto mm : m) {
                res += mm.second * (mm.second - 1);
            }
        }
        return res;
    }
    int dis(vector<int>& p1, vector<int>& p2) {
        return pow(p1[0] - p2[0], 2) + pow(p1[1] - p2[1], 2);
    }
};