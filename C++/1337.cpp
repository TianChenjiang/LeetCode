class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        map<int, set<int>> m; //数量 - 行号
        vector<int> all, res;
        for (int i = 0; i < mat.size(); i++) {
            int sum = accumulate(mat[i].begin(), mat[i].end(), 0);
            m[sum].insert(i);
        }
        int n = 0;
        for (auto mm : m) {
            all.insert(all.end(), mm.second.begin(), mm.second.end());
        }

        for (int i = 0; i < k; i++) {
            res.push_back(all[i]);
        }
        return res;
    }
};