class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> res;
        if (s.size() < 3) return res;
        for (int i = 0; i < s.size() - 2; i++) {
            int j = i+1;
            for (; j < s.size(); j++) {
                if (s[j] != s[i]) break;
            }
            if (j - i >= 3) res.push_back({i, j-1});
            i = j-1;
        }
        return res;
    }
};