class Solution {
public:
    bool isAllZero(vector<int> &counts) {
        for (int i : counts) {
            if (i != 0) return false;
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        int l = 0, r = 0, n = s2.size(), m = s1.size();
        vector<int> counts(26, 0);
        for (char c : s1) {
            counts[c-'a']++;
        }

        while (r < n) {
            counts[s2[r]-'a']--;
            while (r - l + 1 > m) {
                counts[s2[l]-'a']++;
                l++;
            }
            if (isAllZero(counts)) return true;
            r++;
        }
        return false;
    }
};