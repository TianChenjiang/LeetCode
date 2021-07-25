class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        int n = adjacentPairs.size() + 1;
        vector<int> res(n);
        unordered_map<int, vector<int>> m;
        //找出边界
        for (auto vec : adjacentPairs) {
            m[vec[0]].push_back(vec[1]);
            m[vec[1]].push_back(vec[0]);
        }

        bool hasStart = false;
        for (auto mm : m) {
            if (mm.second.size() == 1) {
                if (!hasStart) {
                    res[0] = mm.first;
                    hasStart = true;
                }
                else res[n-1] = mm.first;
            }
        }
        // cout << res[0] << " " << res[n-1] << endl;
        for (int i = 1; i < n - 1; i++) {
            if (m[res[i-1]].size() == 1) res[i] = m[res[i-1]][0];
            else {
                int first = m[res[i-1]][0];
                res[i] = (first == res[i-2]) ? m[res[i-1]][1] : first;
            }
        }
        return res;
    }
};