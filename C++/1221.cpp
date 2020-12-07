class Solution {
public:
    int balancedStringSplit(string s) {
        int res = 0;
        int rcnt = 0, lcnt = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'R') rcnt++;
            if (s[i] == 'L') lcnt++;
            if (rcnt == lcnt && rcnt != 0) {
                res++;
            }
        }
        return res;
    }
};