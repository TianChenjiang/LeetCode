class Solution {
public:
    static bool cmp(string& s1, string& s2) {
        if (s1.size() == s2.size()) {
            return s1 < s2;
        } else return s1.size() > s2.size();
    }
    string findLongestWord(string s, vector<string>& dictionary) {
        sort(dictionary.begin(), dictionary.end(), cmp);
        for (string dic : dictionary) {
            if (match(s, dic)) return dic;
        }
        return "";
    }

    //在s1里找s2
    bool match(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        int l = 0, r = 0;
        while (l < n && r < m) {
            if (s1[l] == s2[r]) {
                l++; r++;
            } else {
                l++;
            }
        }
        return r == m;
    }
};