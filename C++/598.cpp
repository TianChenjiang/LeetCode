class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int res = 0, s = ops.size();
        int minM = m, minN = n;
        for (auto op : ops) {
            minM = min(op[0], minM);
            minN = min(op[1], minN);
        }
        return minM * minN;
    }
};