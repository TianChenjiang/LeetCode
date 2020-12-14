class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, int> m; // 按顺序排的字符串 - 结果数组的索引
        int cnt = 0;  // 结果vector的索引
        for (string str : strs) {
            string t = str;
            sort(t.begin(), t.end());
            if (m.find(t) != m.end()) {
                int i = m[t];
                res[i].push_back(str);
            } else {
                m[t] = cnt++;
                res.push_back({str}); //新建结果的一维数组
            }
        }
        return res;
    }
};