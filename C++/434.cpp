class Solution {
public:
    int countSegments(string s) {
        if (s.empty()) return 0;
        int res = 0, n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] != ' ') {
                while (s[i] != ' ' && i < n) i++;
                res++;
                i--;
            }
        }
        return res;
    }
};