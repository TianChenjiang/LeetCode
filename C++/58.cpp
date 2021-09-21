class Solution {
public:
    int lengthOfLastWord(string s) {
        int res = 0, n = s.size();
        int l = 0, r = s.size() - 1;
        while (r >= 0 && s[r] == ' ') r--;
        l = r;
        while (l >= 0 && s[l] != ' ') l--;
        return r - l;
    }
};