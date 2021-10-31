class Solution {
public:
    set<string> st;
    int len, max, n;
    string ss;
    vector<string> removeInvalidParentheses(string s) {
        int l = 0, r = 0;
        ss = s;
        n = s.size();
        for (char chr : s) {
            if (chr == '(') l++;
            if (chr == ')') r++;
        }
        max = min(l, r);
        dfs(0, 0, "");
        return vector<string>(st.begin(), st.end());
    }
    void dfs(int ind, int score, string cur) {
        if (score < 0 || score > max) return;
        if (ind == n) {
            if (score == 0 && cur.size() >= len) {
                if (cur.size() > len) st.clear();
                len = cur.size();
                st.insert(cur);
            }
            return;
        }
        if (ss[ind] == '(') {
            dfs(ind + 1, score+1, cur + ss[ind]);
            dfs(ind + 1, score, cur);
        } else if (ss[ind] == ')') {
            dfs(ind + 1, score-1, cur + ss[ind]);
            dfs(ind + 1, score, cur);
        } else {
            dfs(ind + 1, score, cur + ss[ind]);
        }
    }
    bool isValid(string s) {
        int cnt = 0;
        for (char chr : s) {
            if (chr == '(') cnt++;
            else if (chr == ')') cnt--;
            if (cnt < 0) return false;
        }
        return cnt == 0;
    }
};