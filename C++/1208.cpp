class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        int l = 0, r = 0;
        int res = 0, curCost = 0;
        while (r < n) {
            curCost += abs(s[r] - t[r]);
            while (curCost > maxCost) {
                curCost -=  abs(s[l] - t[l]);
                l++;
            }
            res = max(r - l + 1, res);
            r++;
        }
        return res;
    }
};