class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> m;
        for (auto path : paths) {
            m.insert(path[0]);
        }
        for (auto path : paths) {
            if (!m.count(path[0])) return path[0];
            if (!m.count(path[1])) return path[1];
        }
        return "";
    }
};