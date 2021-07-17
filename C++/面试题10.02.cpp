class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> m;
        for (string str : strs) {
            string cur = str;
            sort(cur.begin(), cur.end());
            m[cur].push_back(str);
        }
        for (auto mm : m) {
            vector<string> vec;
            for (string str : mm.second) {
                vec.push_back(str);
            }
            res.push_back(vec);
        }
        return res;
    }
};