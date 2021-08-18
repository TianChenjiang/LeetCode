class Solution {
public:
    string reverseVowels(string s) {
        int n = s.size();
        int l = 0, r = n - 1;
        while (l < r) {
            while (!isVowel(s[l]) && l < n) l++;
            while (!isVowel(s[r]) && r > 0) r--;
            if (l < r) {
                swap(s[l], s[r]);
                l++;
                r--;
            }
        }
        return s;
    }
    bool isVowel(char c) {
        string s = "aeiouAEIOU";
        return find(s.begin(), s.end(), c) != s.end();
    }
};