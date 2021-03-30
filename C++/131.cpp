class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        backtrack(s, res, path);
        return res;
    }

    void backtrack(string s, vector<vector<string>>& res, vector<string> &path) {
        if (s.empty()) {
            res.push_back(path);
            return;
        }
        for (int i = 1; i <= s.size(); i++) {
            string p = s.substr(0,i);
            if (isPalindrome(p)) {
                path.push_back(p);
                backtrack(s.substr(i), res, path);
                path.pop_back();
            }
        }
    }


    bool isPalindrome(string str) {
        if (str.empty()) return true;
        int lo = 0, hi = str.size()-1;
        while (lo <= hi) {
            if (str[lo++] != str[hi--]) return false;
        }
        return true;
    }
};