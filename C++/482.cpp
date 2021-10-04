class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string res = "";
        int n = s.size(), cnt = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '-') continue;
            if (cnt == k && (cnt = 0) >= 0) res += '-'; //注意这条语句的位置在cnt++之前，这样反向遍历到最开头，当分组后面还有字母的时候才会加-。
            res += toupper(s[i]);
            cnt++;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};