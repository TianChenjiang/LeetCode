class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.size();
        if (n != t.size()) return false;
        unordered_map<char, char> m, mm;
        for (int i = 0; i < n; i++) {
            char c = s[i];
            if (m.find(c) == m.end() && mm.find(t[i]) == mm.end()) { // 没有存
                m[c] = t[i];
                mm[t[i]] = c;
            } else if (m[c] == t[i]) continue;
            else return false;
        }
        return true;
    }
};