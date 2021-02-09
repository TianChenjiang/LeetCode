class Solution {
public:
    static bool cmp(pair<char, int> p1, pair<char, int> p2) {
        return p1.second < p2.second;
    }

    int characterReplacement(string s, int k) {
        int l = 0, r = 0, n = s.size();
        int res = 0, maxCnt = 0;
        int counts[26];
        memset(counts, 0, sizeof(counts));
        while (r < n) {
            counts[s[r] - 'A']++;
            // maxCnt = max_element(m.begin(), m.end(), cmp)->second;
            maxCnt = max(maxCnt, counts[s[r] - 'A']);
            while (r - l + 1 - maxCnt > k) {
                counts[s[l] - 'A']--;
                l++;
            }
            res = max(res, r - l + 1);
            r++;
        }
        return res;
    }
};