class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> m;
        vector<string> res;
        int n = s.size();
        if (n < 10) return res;
        for (int i = 0; i <= n - 10; i++) {
            string sub = s.substr(i, 10);
            m[sub]++;
            if (m[sub] == 2) res.push_back(sub);
        }
        return res;
    }
};